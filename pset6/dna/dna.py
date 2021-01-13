from sys import argv, exit
import csv
import re


def main():
    # check usage
    if len(argv) != 3:
        print("Usage: python dna.py database.csv sequence.txt")
        exit(1)

    csv_file = open(argv[1], "r")
    database = get_database(csv_file)

    seq_file = open(argv[2], "r")
    sequence = get_sequence(seq_file)

    max_rep = compute_strs(sequence, database)
    print(find_match(max_rep, database))

    csv_file.close()
    seq_file.close()


# read csv in a list of dictioaries
def get_database(file):
    reader = csv.DictReader(file)
    database = []

    for row in reader:
        database.append(dict(row))

    return database


# read sequence in a string
def get_sequence(file):
    for line in file:
        sequence = line.rstrip("\n")

    return sequence


# finds max continuous repetitions of str in dna
def get_max(dna, str):
    repetitions = []
    count = 0
    i = 0
    length = len(str)

    # make a list with number of continuous repetitions 'count'
    while i < len(dna):
        # if found str, count repetition and skip to the end of str
        if dna[i:i + length] == str:
            count += 1
            i += length
            continue
        else:
            repetitions.append(count)
            count = 0
        i += 1

    return max(repetitions)


# returns a list with the max values found in dna for every str in database
def compute_strs(dna, database):
    strs = []

    for key in database[0].keys():
        if (key != 'name'):
            strs.append(key)

    max_rep = []

    for str in strs:
        max_rep.append(get_max(dna, str))

    return max_rep


# iterate through each person in database to find a match
def find_match(reps, database):
    match = 'no match'

    # get a list of strs for each person in database
    for person in database:
        person_reps = []

        for key in person.keys():
            if key == 'name':
                continue
            person_reps.append(int(person[key]))

        # we found a match
        if person_reps == reps:
            match = person['name']

    return match


if __name__ == "__main__":
    main()