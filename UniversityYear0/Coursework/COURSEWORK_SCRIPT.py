# Author: Ricardo Lopes
# Contact: lopesr@edgehill.ac.uk
# Date: 30 January 2025
# Doomsday Algorithm

# Days that are Friday of that month
anchor_dates = [3, 28, 14, 4, 9, 6, 11, 8, 5, 10, 7, 12]
dow_desc = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]
current_year = 2025
# 4 bcs it's the index for Friday in dow_desc
current_anchor = 4

user_day = int(input("Enter the day: "))
user_month = int(input("Enter the month: "))

# Finds the anchor date for that month (-1 as 0 index)
anchor = anchor_dates[user_month-1]

print(f"User Date: {user_day}/{user_month} - Anchor: {anchor}/{user_month}")

# Finds the difference between the bigger of the two numbers, and the smaller (e.g. 28/14 will become 28-14)
# Ensures that the difference between anchor day and user day will be a positive answer
difference = max(anchor, user_day) - min(anchor, user_day)

print(f"The difference between the user defined day ({user_day}) and the anchor day ({anchor}) in month {user_month} is {difference} days")

# (Input day - Friday date) THEN add (35 + 4)
# e.g. 20/3 is (20 - 14) + (35 + 4) = 45, then 45 % 7 = 3 (don't forget zero index so it's the 5th day)
# Note that 35 % 7 = 0, so it just ensures positive and can be ignored? I think
user_dow = (user_day - anchor + 35 + current_anchor) % 7

print(f"{user_day}/{user_month}/{current_year} is {dow_desc[user_dow]}")


# (this is the corrected ver)