import csv
import sys


def main():
    # TODO: Check for command-line usage
    # Status: Seems COMPLETE
    if len(sys.argv) != 3:
        print("Invalid use of command line arguments.")
        return

    # TODO: Read database file into a variable
    # Status: Seems complete
    people = {}
    i = 0
    with open(sys.argv[1]) as csvfile:
        file_reader0 = csv.DictReader(csvfile)
        for person in file_reader0:
            people[i] = person
            i += 1

    # TODO: Read DNA sequence file into a variable
    # Status: Seems complete
    DNA = None

    with open(sys.argv[2]) as file:
        # Get first line
        file_reader1 = csv.reader(file)
        row = next(file_reader1)
        # Typecast to string and assign
        DNA = str(row)

    # TODO: Find longest match of each STR in DNA sequence
    # Status: Seems complete
    sample = people[0]
    counts = {}
    for STR in sample:
        STR = STR.strip("\n")

        length = longest_match(DNA, STR)

        counts[STR] = length

        # print(counts[STR])

    # print(counts)

    # TODO: Check database for matching profiles
    i = 0
    for index in people:
        # Get every person from the people dictionary
        person = people[index]
        # Inspect each STR
        match = False
        for STR in person:
            # Use key to get value, rather than name of each STR, and typecast to string for comparing
            currentSTR = str(person[STR])
            compareSTR = str(counts[STR])
            i += 1
            # Do not compare name, only STR values
            if currentSTR != compareSTR and currentSTR != person["name"]:
                # Doesn't match, move to next person
                match = False
                break
            else:
                # True for this iteration and continue to see if remains true for all iterations
                match = True
                continue

        # Find person, if there is one, that looped through with all STR set to 'True'
        if match == True:
            print(person["name"])
            return

    print("No match.")
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
