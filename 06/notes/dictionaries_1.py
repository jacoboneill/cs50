people = {
    "jane": "07123456789",
    "john": "07234567891",
}

name = input("Name: ")

if name.lower() in people:
    print(f"Found: {people[name.lower()]}")
else:
    print("Not found.")
