days = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

# Get day's index from user input
dayIndex = 10
while dayIndex not in range(7):
    dayIndex = int(input("Please enter a number between 0 (for Mon) and 6 (Sun): "))

print(f"{dayIndex} is the index for {days[dayIndex]}.")

# Get index based on user's day input
day = 10
while day not in days:
    day = input("Please enter a day of the week: ").capitalize()[:3]

if day in days:
    index = days.index(day)
    print(f"{day} has the index {index}.")
else:
    print(f"{day} not found.")

