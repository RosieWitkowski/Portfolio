from cs50 import get_int


def main():
    # Get input (with range validation)
    height = -10
    while height < 1 or height > 8:
        height = get_int("Height: ")

    gaps = height - 1
    length = 1
    # For each row
    for _ in range(height):
        # Print spaces
        for _ in range(gaps):
            print(" ", end="")

        # Print hash symbols
        for _ in range(length):
            print("#", end="")

        # Prepare for next row
        print()

        gaps -= 1
        length += 1


if __name__ == "__main__":
    main()
