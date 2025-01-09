import csv
import sys


def main():
    if len(sys.argv) != 3:
        print("Usage: python dna.py database input")
        sys.exit(1)

    database = load_database(sys.argv[1])

    sequence = load_sequence(sys.argv[2])

    strs = [x for x in database[0].keys() if x != "name"]
    sequence = get_longest_matches(database, sequence, strs)

    print(search_database(database, sequence, strs))

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


def load_database(path):
    database = []
    with open(sys.argv[1], "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            entry = {}
            for key, value in row.items():
                if value.isnumeric():
                    entry[key] = int(value)
                else:
                    entry[key] = value
            database.append(entry)
    return database


def load_sequence(path):
    sequence = {}
    with open(sys.argv[2], "r") as file:
        sequence["sequence"] = file.read().strip()

    return sequence


def get_longest_matches(database, sequence, strs):
    for s in strs:
        sequence[s] = longest_match(sequence["sequence"], s)

    return sequence


def search_database(database, sequence, strs):
    for entry in database:
        for s in strs:
            if entry[s] != sequence[s]:
                break
        else:
            return entry["name"]
    else:
        return "No match"


main()
