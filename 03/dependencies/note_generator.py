import os
import subprocess

temp = "../tmp"
print(f"Making temporary directory at {temp}")
subprocess.run(f"mkdir -p {temp}", shell=True, check=True)

dirs = [x for x in os.listdir() if os.path.isdir(x)]
print(dirs)
for dir in dirs:
    out = temp + '/' + dir + ".pdf"
    print(f"Converting {dir}/note.md to {out}")
    subprocess.run(f"pandoc note.md -o ../{out} --pdf-engine=xelatex", shell=True, check=True, cwd=dir)

# pdf_files = os.listdir(temp)
pdf_files = [f"{temp}/{x}" for x in os.listdir(temp)]
print(f"Merging pdf's in {temp} to ../notes.pdf")
subprocess.run(f"pdfunite {' '.join(pdf_files)} ../notes.pdf", shell=True, check=True)

print(f"Removing directory {temp} and contents")
subprocess.run(f"rm -rf {temp}", shell=True, check=True)
