def main():
    # Get year from user input
    year = int(input("Year: "))

    # Validate leap year
    if is_leap_year(year):
        print("Leap year.")
    else:
        print("Not a leap year.")


def is_leap_year(year):
    if year % 4 == 0 and year % 100 != 0:
        return True
    elif year % 100 == 0 and year % 400 == 0:
        return True
    else:
        return False
    


if __name__ == "__main__":
    main()