#!/usr/bin/env python3
import argparse
from pathlib import Path
import os
import re

def parse_func_name(func_name):
    # Built a list of tuples. Element 0 is function name, Element 1 is file path
    functions = [(s.stem,str(s)) for s in Path("asm").rglob("*.s") if "nonmatchings" in str(s)]
    matches = [x for x in functions if x[0] == func_name]
    if len(matches) == 0:
        print(f"Unable to find function `{func_name}`")
        exit(1)
    if len(matches) > 1:
        print(f"Found multiple functions called `{func_name}`")
        print(f"You will need to specify which function you want.")
        print(f"=================================================")
        for i,match in enumerate(matches):
            print(f"{i}:{match[1]}")
        print(f"=================================================")
        choice_num = int(input("Enter the number matching which function you want here: "))
        return matches[choice_num][1]
    if len(matches) == 1:
        return matches[0][1]
    
def get_c_filename(asm_filename):
    assert "asm/us" in asm_filename and "/nonmatchings/" in asm_filename
    # Step 1: Replace asm/us for src
    srcpath = asm_filename.replace("asm/us", "src")
    # Step 2: Remove the nonmatchings
    no_nonmatchings = srcpath.replace("/nonmatchings/", "/")
    # Little known rpartition drops the function name to get the last directory, which should be c file name.
    c_filename = no_nonmatchings.rpartition("/")[0] + ".c"
    assert os.path.exists(c_filename)
    return c_filename

# Find jump tables in code, locate the rodata and paste at the end of the file
def resolve_jumptable(asm_filename):
    with open(asm_filename,'r+') as asm_file:
        lines = asm_file.readlines()
        for i,line in enumerate(lines):
            # looking for a line with a jr, but not with $ra
            if 'jr' not in line or '$ra' in line:
                continue
            print("bingbong")
            print(line)
            jumpreg = line.split()[-1]
            if 'nop' not in lines[i-1]:
                exit(1)
            #Build a regex to search for the standard jump table setup
            lw_regex = 'lw\s*\\' + jumpreg + ', %lo\(([^)]*)\)\(\$at\)'
            jumptable_name = re.search(lw_regex,lines[i-2]).group(1)
            print(f"Jumptable: {jumptable_name}")
            addu_regex = 'addu\s*\$at, \$at, \\' + jumpreg
            adducheck = re.search(addu_regex,lines[i-3])
            if adducheck == None:
                exit(2)
            lui_regex = 'lui\s*\$at, %hi\(' + jumptable_name + '\)'
            luicheck = re.search(lui_regex,lines[i-4])
            if luicheck == None:
                exit(3)
            #confirmed the jump table is as expected. Now find it.
            paths = list(Path('asm').rglob("*.rodata.s")) + \
                    list(Path('asm').rglob("*.data.s"))
            for rodata_file in paths:
                with open(rodata_file) as f:
                    rodata = f.read()
                    if jumptable_name not in rodata:
                        continue
                    all_rodata_lines = rodata.split('\n')
                    outlines = ['.section .rodata']
                    for line in all_rodata_lines:
                        if jumptable_name in line or len(outlines) > 1:
                            outlines.append(line)
                            if len(line) == 0:
                                print("Outputting")
                                print(outlines)
                                asm_file.write('\n'.join(outlines))
                                break

if __name__ == "__main__":
    # Start by finding the function
    parser = argparse.ArgumentParser(description="Make decomp.me page for a function")
    parser.add_argument(
        "func_name",
        help="Name of function to create a decomp.me page for",
    )
    args = parser.parse_args()
    asm_filename = parse_func_name(args.func_name)
    print(asm_filename)
    c_filename = get_c_filename(asm_filename)
    # Function is found. Now resolve any jump tables by appending rodata
    resolve_jumptable(asm_filename)
    # Decompile function locally. 

    import_string = f'tools/decomp-permuter/import.py {c_filename} {asm_filename}'
    print(f"Calling {import_string}")
    os.system(import_string)
