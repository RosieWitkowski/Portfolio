# 3136. Valid Word
# Solution: https://leetcode.com/problems/valid-word/solutions/6961994/beats-100-clean-simple-beinner-friendly-logic-detailed-description/

def isValid(word):
    # Must have at least 3 characters and be alphanumeric
    if len(word) < 3 or not word.isalnum():
        return False

    # Must contain at least one vowel and one constanent
    word = word.upper()
    vowels = 'AEIOU'
    vowl, const = 0, 0
    for char in word:
        # Skip any numbers to ensure altnerative of vowel is constanent
        if char.isdigit():
            continue

        if char in vowels:
            vowl += 1
        else:
            const += 1

        # Only need a minimum 1 of each so can return
        if vowl > 0 and const > 0:
            return True
    return False 

print(isValid("234Adas")) # Expected output: True
print(isValid("b3")) # Expected output: False
print(isValid("a3$e")) # Expected output: False
