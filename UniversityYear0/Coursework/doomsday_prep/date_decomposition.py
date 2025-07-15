import datetime

date = input("Date (dd/mm/yy): ")
day = date[:2]
month = date[3:5]
year = date[6:]

# BETTER? VERSION
day, month, year = date.split("/")
print(day, month, year, day)

print(f"{day}\n{month}\n{year}")