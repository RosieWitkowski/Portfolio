dow_desc = ["Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun"]

anchor_pattern = {
    0: 1,
    100: 6,
    200: 4,
    300: 2
}

year = 2025
century_start = (year // 100) * 100
century_anchor = anchor_pattern[century_start % 400]
century_doomsday = dow_desc[century_anchor]

# Add years and leap years (same as expanded.py)
current_anchor = (century_anchor + (year - century_start) + ((year - century_start) // 4)) % 7
print(dow_desc[current_anchor])

