#!/usr/bin/env python3
import argparse
from pathlib import Path
import os

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

def send_to_decompme(data):
    #This is copied directly from decomp-permuter/import.py
    api_base = os.environ.get("DECOMPME_API_BASE", "https://decomp.me")
    compiler_name = get_decompme_compiler_name(compiler, settings, api_base)
    source, context = prune_and_separate_context(source, args.prune, func_name)
    print("Uploading...")
    try:
        post_data = urllib.parse.urlencode(
            {
                "name": func_name,
                "target_asm": asm_cont,
                "context": context,
                "source_code": source,
                "compiler": compiler_name,
                "compiler_flags": get_compiler_flags(compiler),
                "diff_label": func_name,
            }
        ).encode("ascii")
        with urllib.request.urlopen(f"{api_base}/api/scratch", post_data) as f:
            resp = f.read()
            json_data: Dict[str, str] = json.loads(resp)
            if "slug" in json_data:
                slug = json_data["slug"]
                print(f"https://decomp.me/scratch/{slug}")
            else:
                error = json_data.get("error", resp)
                print(f"Server error: {error}")
    except Exception as e:
        print(e)
    return

parser = argparse.ArgumentParser(description="Make decomp.me page for a function")
parser.add_argument(
    "func_name",
    help="Name of function to create a decomp.me page for",
)
parser.add_argument(
    "--dry",
    action="store_true",
    help="Perform a dry run, generating local files but not uploading to decompme",
)

args = parser.parse_args()
asm_filename = parse_func_name(args.func_name)
print(asm_filename)
c_filename = get_c_filename(asm_filename)
import_string = f'tools/decomp-permuter/import.py {c_filename} {asm_filename}'
if not args.dry:
    import_string.append(' --decompme')
print(f"Calling {import_string}")
os.system(import_string)
