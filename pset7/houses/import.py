from sys import argv, exit
import csv
from cs50 import SQL


def main():
    # check usage
    if len(argv) != 2:
        print("Usage: python import.py filename.csv")
        exit(1)

    file = open(argv[1], "r")
    csv_data = get_data(file)

    # get all data from csv sorted in lists
    firsts, middles, lasts = get_names(csv_data)
    houses = get_field(csv_data, 'house')
    births = get_field(csv_data, 'birth')

    db = SQL("sqlite:///students.db")

    # assuming all lists have the same lenght
    for i in range(len(firsts)):
        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                   firsts[i], middles[i], lasts[i], houses[i], int(births[i]))

    file.close()


# returns three lists with first, middle and last names
def get_names(data):
    firsts = []
    middles = []
    lasts = []

    for person in data:
        name = person['name'].split()

        firsts.append(name[0])
        if len(name) == 3:
            middles.append(name[1])
            lasts.append(name[2])
        # if a person doesn't have a middle name, then middle field is None
        elif len(name) == 2:
            middles.append(None)
            lasts.append(name[1])

    return firsts, middles, lasts


# returns a list with the values of a key 'field'
def get_field(data, field):
    list = []

    for person in data:
        list.append(person[field])

    return list


# read csv in a list of dictioaries
def get_data(file):
    reader = csv.DictReader(file)
    data = []

    for row in reader:
        data.append(dict(row))

    return data


if __name__ == "__main__":
    main()