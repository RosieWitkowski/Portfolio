# 1431. Kids With the Greatest Number of Candies

def kidsWithCandies(candies, extraCandies):
        bools = []
        maxCandies = max(candies)
        for kid in candies:
            if kid + extraCandies >= maxCandies:
                bools.append(True)
            else:
                bools.append(False)
        return bools

print(kidsWithCandies([2,3,5,1,3], 3)) # Expected output: [True,True,True,False,True]
print(kidsWithCandies([4,2,1,1,2], 1)) # Expected output: [True,False,False,False,False]
print(kidsWithCandies([12,1,12], 10)) # Expected output: [True,False,True]