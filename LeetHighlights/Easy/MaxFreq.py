# 3541. Find Most Frequent Vowel and Consonant
# Solution: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/solutions/6877148/easiest-beginner-friendly-high-readabili-60or/

def maxFreqSum(s):
    maxVow, maxConst = 0,0
    
    for char in s:
        freq = s.count(char)
        if char in 'aeiou':
            if freq > maxVow:
                maxVow = freq
        else:
            if freq > maxConst:
                maxConst = freq

    return maxVow + maxConst

print(maxFreqSum("successes")) # Expected output: 6
print(maxFreqSum("aeiaeia")) # Expected output: 3