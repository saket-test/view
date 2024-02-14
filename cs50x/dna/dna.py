import csv
import sys


def main():
    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    # TODO: Read database file into a variable
    database = []
    try:
        with open(sys.argv[1]) as dna_file:
            reader = csv.DictReader(dna_file)
            for i in reader:
                database.append(i)
    except:
        sys.exit(2)

    dna_list = [item for item in database[0] if item != "name"]
    dna_list_length = len(dna_list)
    dna_list_string = []

    for i in dna_list:
        temp = [char for char in i]
        dna_list_string.append(temp)

    # TODO: Read DNA sequence file into a variable
    sequence = []
    try:
        with open(sys.argv[2]) as sq_file:
            reader = sq_file.read()
            for i in reader:
                sequence.append(i)
    except:
        sys.exit(2)

    # TODO: Find longest match of each STR in DNA sequence
    longestMatch = {}
    for i in range(dna_list_length):
        longestMatch[dna_list[i]] = longest_match(sequence, dna_list_string[i])

    # TODO: Check database for matching profiles
    for person in database:
        matches = 0
        for dna in dna_list:
            if int(person[dna]) == longestMatch[dna]:
                matches += 1
        if matches == dna_list_length:
            print(person["name"])
            return
    else:
        print("No match")
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


main()
