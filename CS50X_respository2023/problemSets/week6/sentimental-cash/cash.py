from cs50 import get_float


def main():
    # Input, positive only
    change = -10
    while change < 0:
        change = get_float("Change owned: ")

    coins = 0
    reduce = 0

    # Until no further change required
    while change >= 0.01:
        # Find the amount to remove, depending on current running total
        if change > 0.24:
            reduce = 0.25
        elif change > 0.09:
            reduce = 0.10
        elif change > 0.04:
            reduce = 0.05
        else:
            reduce = 0.01

        # Remove the amount
        change -= reduce
        change = round(change, 2)
        # Add to coins
        coins += 1

        reduce = 0

    print(coins)


if __name__ == "__main__":
    main()
