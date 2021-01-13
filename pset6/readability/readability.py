from cs50 import get_string


def main():
    text = get_string("Text: ")

    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)

    L = letters * 100.0 / words    # average of letters for 100 words
    S = sentences * 100.0 / words  # average of sentences for 100 words

    index = int(round((0.0588 * L) - (0.296 * S) - 15.8, 0))  # Coleman-Lieu index of readability formula

    print_grade(index)


def count_letters(text):
    letters = 0

    for i in range(len(text)):
        c = text[i]
        if(c.isalpha()):
            letters += 1

    return letters


def count_words(text):
    words = 0

    for i in range(len(text)):
        c = text[i]
        if c == " ":
            words += 1
    # to count the last word
    words += 1

    return words


def count_sentences(text):
    sentences = 0

    for i in range(len(text)):
        c = text[i]
        if c == "." or c == "!" or c == "?":
            sentences += 1

    return sentences


def print_grade(index):
    if index < 1:
        print("Before Grade 1")
    elif index >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {index}")


if __name__ == "__main__":
    main()