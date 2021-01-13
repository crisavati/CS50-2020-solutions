from sys import argv, exit
import csv
from cs50 import SQL


def main():
    # check usage
    if len(argv) != 2:
        print("Usage: python roster.py house_name")
        exit(1)

    db = SQL("sqlite:///students.db")
    data = db.execute("SELECT * FROM students WHERE house = ? ORDER BY last, first", argv[1])

    firsts, middles, lasts, years = sort_lists(data)

    # assuming all lists have the same lenght
    for i in range(len(firsts)):
        print(firsts[i] + " " + middles[i], end="")
        if middles[i] != "":
            print(" ", end="")
        print(lasts[i] + ", born " + str(years[i]))


# given list, a list of dicts for each student of a house, this function returns
# four lists with first, middle and last names, and the birthyears
def sort_lists(list):
    firsts = []
    middles = []
    lasts = []
    years = []

    for row in list:
        firsts.append(row['first'])
        if row['middle'] != None:
            middles.append(row['middle'])
        else:
            middles.append("")
        lasts.append(row['last'])
        years.append(row['birth'])

    return firsts, middles, lasts, years


if __name__ == "__main__":
    main()