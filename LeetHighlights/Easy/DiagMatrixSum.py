# 1572. Matrix Diagonal Sum
# Solution: https://leetcode.com/problems/matrix-diagonal-sum/solutions/6971026/beats-100-clear-intuitive-logic-beginner-37bb/

def diagonalSum(mat):    
    # Square so only need length not height and width
    ttl, length = 0, len(mat)

    # Confirms matrix, else returns early
    try:
        mat[0][1]
    except: 
        return print(mat[0])

    # Diagonal left
    for x in range(length):
        ttl += mat[x][x]

    # Diagonal right
    y = length - 1
    for x in range(length):
        ttl += mat[y][x]
        y -= 1

    # Remove middle if odd 
    if length % 2 != 0:
        middle = (length - 1) // 2
        ttl -= mat[middle][middle] 

    return print(ttl)

diagonalSum([[1,2,3],[4,5,6],[7,8,9]]) # Expected output: 25
diagonalSum([[1,1,1,1],[1,1,1,1],[1,1,1,1],[1,1,1,1]]) # Expected output: 8
diagonalSum([5]) # Expected output: 5
diagonalSum([5, 10]) #  Expected output: 5
diagonalSum([[2, 2], [2, 2]]) # Expected output: 8

