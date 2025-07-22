# 2000. Reverse Prefix of Word
# Solution: https://leetcode.com/problems/reverse-prefix-of-word/

def reversePrefix(ch, word) -> str:
        if ch not in word:
            return word
            
        index = word.find(ch)

        return word[:index+1][::-1]+word[index+1:]

print(reversePrefix("d", "abcdefd")) # Expected Output: "dcbaefd"
print(reversePrefix("z", "xyxzxe")) # Expected Output: "zxyxxe"
print(reversePrefix("z", "abcd")) # Expected Output: "abcd"
