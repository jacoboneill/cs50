import os
import subprocess

temp = "../tmp"
print(f"Making temporary directory at {temp}")
subprocess.run(f"mkdir -p {temp}", shell=True, check=True)

md_files = []
for root, dirs, files in os.walk("."):
    for file in files:
        if file.split(".")[-1] == 'md':
            md_files.append(os.path.join(root, file))


for file in md_files:
    filename = '.'.join(file.split('/')[-1].split('.')[:-1]) + '.pdf'
    output = f"{temp}/{filename}"
    print(f"Converting {file} to pdf in {output}")
    subprocess.run(f"pandoc {file} -o {output}", shell=True, check=True)

pdf_files = ' '.join([f"{temp}/{x}" for x in sorted(os.listdir(temp))])
print(f"Merging md files in {temp} to ../notes.pdf")
subprocess.run(f"pdfunite {pdf_files} ../notes.pdf", shell=True, check=True)

print(f"Removing {temp} and contents")
subprocess.run(f"rm -rf {temp}", shell=True, check=True)
