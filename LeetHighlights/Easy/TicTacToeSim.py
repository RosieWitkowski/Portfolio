# 1275. Find Winner on a Tic Tac Toe Game
# Solution: https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/description/ 

def tictactoe(moves) -> str:
    grid = [[0, 0, 0],
            [0, 0, 0],
            [0, 0, 0]]

    turn = 'A'
    turns = 0
    for move in moves:
        row, col = move[0], move[1]
        # Update board (only if selected square is empty)
        if grid[row][col] == 0:
            grid[row][col] = turn

        # Check for winner (if row match, if diagonal, if alternative diagonal, if column)
        if (grid[row] == [turn, turn, turn] 
            or (grid[0][0] == turn and grid[1][1] == turn and grid[2][2] == turn) 
            or (grid[0][2] == turn and grid[1][1] == turn and grid[2][0] == turn)
            or (grid[0][col] == turn and grid[1][col] == turn and grid[2][col] == turn)
            ):
            print(f"{turn} wins!")
            return 

        # Check for full grid 
        turns += 1
        if turns == 9:
            print("Draw")
            return 

        # Swap turn
        if turn == 'A':
            turn = 'B'
        else:
            turn = 'A'

    print("Pending")

tictactoe([[0,0],[2,0],[1,1],[2,1],[2,2]])
tictactoe([[0,0],[1,1],[0,1],[0,2],[1,0],[2,0]])
tictactoe([[0,0],[1,1],[2,0],[1,0],[1,2],[2,1],[0,1],[0,2],[2,2]])