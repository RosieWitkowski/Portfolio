# 2798. Number of Employees Who Met the Target
# Solution: https://leetcode.com/problems/number-of-employees-who-met-the-target/solutions/6863574/highly-easy-and-effecient-by-codeabit04-01j6

def numberOfEmployeesWhoMetTarget(hours, target) -> int:
    hours = list(filter(lambda x: x >= target, hours))
    return len(hours)

print(numberOfEmployeesWhoMetTarget([0,1,2,3,4], 2)) # Expected output: 3
print(numberOfEmployeesWhoMetTarget([5,1,4,2,2], 6)) # Expected output: 0