import os
import subprocess

def create_temp_dir(dir):
    print(f"Creating temporary directory at {dir}")
    subprocess.run(f"mkdir -p {dir}", shell=True, check=True)

def copy_code(directory, file):
    with open(f"./{directory}/{file}", 'r') as f:
        return f"```c\n{f.read().strip()}\n```"

def run_make(directory):
    subprocess.run("make", shell=True, check=True, cwd=f"./{directory}")

def generate_md_file(directory, output):
    print(f"Generating md file for {directory} into {output}")

    title = directory.title().replace("_", " ") if directory.split(".")[-1] != 'c' else directory
    note = f"# {title}\n\n"

    c_files = [x for x in os.listdir(directory) if x.split(".")[-1] == 'c']

    for i, c_file in enumerate(c_files):
        if len(c_files) > 1:
            note += f"## {c_file}\n\n"
        
        note += copy_code(directory, c_file)
        
        if i != len(c_files) - 1:
            note+="\n\n"

    with open(output, 'w') as f:
        f.write(note)

def convert_md_to_pdf(md_file):
    md_dir = "/".join(md_file.split("/")[:-1])
    md_name = md_file.split("/")[-1]
    pdf_name = md_file.split(".md")[0] + ".pdf"
    print(f"Converting {md_file} to {pdf_name}")
    subprocess.run(f"pandoc {md_name} -o {pdf_name}", shell=True, check=True, cwd=md_dir)

    print(f"Deleting {md_file}")
    os.remove(md_file)

def clean(directory):
    print(f"Deleting {directory} and contents")
    subprocess.run(f"rm -rf {directory}", shell=True, check=True)

def join_pdfs(directory, output):
    print(f"Merging all pdfs into {output}")
    pdfs = ' '.join([f"../tmp/{pdf}" for pdf in sorted(os.listdir(directory)) if pdf.split(".")[-1] == 'pdf'])
    subprocess.run(f"pdfunite {pdfs} {output}", shell=True, check=True)

def main():
    temp = "../tmp"
    create_temp_dir(temp)
    
    for dir in [dir for dir in os.listdir() if os.path.isdir(dir)]:
        generate_md_file(dir, f"{temp}/{dir}.md")
        convert_md_to_pdf(f"{temp}/{dir}.md")

    join_pdfs(temp, "./notes.pdf")
    clean(temp)

main()
