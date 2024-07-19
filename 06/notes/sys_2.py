import sys

if len(sys.argv) != 2:
    print("Usage: python3 sys_2.py NAME")
    sys.exit(1)
else:
    print(f"Hello, {sys.argv[1]}")
