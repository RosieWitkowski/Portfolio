date = "20/04/2000"

print(date.count("/"))
nums = "01/01/02/03/04/5"
print(nums.count("/"))

day, month, year = date.split("/")

year = int(year)
for n in range(50):
    print(year + n)
print(f"{day}/{month}/{year}")

print("YES" if day.isalpha() else "FALSE")
print(day)
if day.isalpha():
    print("ALPHABETICAL")