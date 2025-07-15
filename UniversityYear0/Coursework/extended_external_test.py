import numpy as np 

dow_desc = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]
anchor_dates = [3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12]

def main():
    """Displays the number of times a given date falls on the same day, in 50 years."""
    # Gets and validates date
    day, month, year, date = get_date()
    
    # Day of first occurence 
    special_day = doomsday(day, month, year)

    # Years that the same date falls on the same weekday
    occurences = []
    for years in range (50):
        year += years 
        if years == 0 or doomsday(day, month, year) == special_day:
            occurences.append(year)

    # Print findings
    print(f"{date} falls on a {dow_desc[special_day]} {len(occurences)} times in the following 50 years: ", end = "")
    for year in occurences:
        print(f"{year} ", end = "")

def get_date():
    """Returns an int day, int month, int year, and string date, by validating input in the format DD/MM/YYYYY."""
    # Validate input
    day, month, year = "DD", "MM", "YY"

    valid = False
    while valid == False:
        date = input("Date: ")
        # Must be in format day/month/year
        if date.count("/") != 2:
            print("Please provide in the format 'DD/MM/YYYY'.")
            continue

        day, month, year = date.split("/")
        
        # Must be numbers
        if not (day.isdigit() and month.isdigit() or year.isdigit()):
            print("Please use numbers only.")
            continue
        
        day, month, year = int(day), int(month), int(year)
        # Specifics (days in month, leap years)
        if validate_date(day, month, year):
            # Everything validated
            valid = True
        else:
            print("invalid date provided.")

    return day, month, year, date


def validate_date(day, month, year):
    """Returns false is any invalidity is found for dates, such as a month being greater than 12 or a day less than 1, etc."""
    month_days = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    
    if day < 1 or month < 1 or year < 0:
        print("Day and month must be at least 1, and year at least 0, ", end = "")
        return False
    # Invalid month 
    elif month > 12:
        print("Provided month must be less than 13, ", end = "")
        return False
    # Invalid day
    elif day > month_days[month - 1]:
        print("Provided day is greater than month's number of days, ", end = "")
        return False 
    # Leap year exception
    elif month == 2 and day == 29:
        if leap_year(year):
            return True 
        else:
            print("Provided year is not a leap year, ", end = "")
    # Everything valid
    else:
        return True 

def doomsday(day, month, year):
     # Get the anchor for that year
    current_anchor = get_current_anchor(year)

    # If it's a leap year, adjust the anchor dates for January and Febuary
    if leap_year(year):
            anchor_dates[0], anchor_dates[1] = 4, 29
    # Revert for any years following a leap year 
    else:
        anchor_dates[0], anchor_dates[1] = 3, 28

    # Find the day, using the original doomsday code
    return original(day, month, current_anchor)

def get_current_anchor(year):
    """Returns the (index) day of the week that a year's doomsday is."""

    # Maps (multiples of) centuries to their doomsday - so 1 is Tue, according to dow_desc
    anchor_pattern = {
        0: 1,
        100: 6,
        200: 4,
        300: 2
    }

    century_start = (year // 100) * 100
    # Pattern for century doomsdays changes every 400 years
    century_anchor = anchor_pattern[century_start % 400]
    
    # Add years and leap years, then find mod 7 for the day of the week it relates to
    years = year - century_start 
    current_anchor = (century_anchor + years + (years // 4)) % 7

    return current_anchor

def leap_year(year):
    """Returns true if the year fits the properties required of a leap year."""
    return True if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0 and year % 100 == 0) else False

# Original code
def original(user_day, user_month, current_anchor):
    # Author: Ricardo Lopes
    # Contact: lopesr@edgehill.ac.uk
    # Date: 30 January 2025
    # Doomsday Algorithm

    anchor = anchor_dates[user_month-1]

    user_dow = (user_day - anchor + 35 + current_anchor) % 7
    return user_dow


if __name__ == "__main__":
    main()