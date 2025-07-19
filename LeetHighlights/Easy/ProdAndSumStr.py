# 1281. Subtract the Product and Sum of Digits of an Integer
# Solution: https://leetcode.com/problems/subtract-the-product-and-sum-of-digits-of-an-integer/solutions/6863586/highly-fast-and-beginner-friendly-by-cod-4rsx/

def subtractProductAndSum(n):
        n = str(n)
        prod, sum = int(n[0]), int(n[0])

        for char in n[1:]:
            prod *= int(char)
            sum += int(char)

        return prod - sum

print(subtractProductAndSum(234)) # Expected output: 15
print(subtractProductAndSum(4421)) # Expected output: 21