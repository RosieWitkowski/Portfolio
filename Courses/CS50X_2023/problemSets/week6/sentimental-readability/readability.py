from cs50 import get_string

#  0.0588 * L - 0.296 * S - 15.8,
#  L is  average number of letters per 100 words
#  S is  average number of sentences per 100 words


def main():
    text = get_string("Text: ")

    # Note that words starts at one, because the first and second words seperated by a space would otherwise count as only 1 word and not 2
    W = 1
    L = 0
    S = 0

    for c in text:
        # Sentence
        if c == "!" or c == "." or c == "?":
            S += 1
        # Word
        elif c == " ":
            W += 1
        # Letter
        elif c.isalpha():
            L += 1

    L = (L / W) * 100
    S = (S / W) * 100

    grade = 0.0588 * L - 0.296 * S - 15.8
    grade = round(grade)

    if grade > 15:
        print("Grade 16+")
    elif grade < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {grade}")


if __name__ == "__main__":
    main()
