
class TicTacToe(object):
    def __init__(self, N=3, player='x'):
        self.N = N
        self.player = player
        self.empty_move = '-'
        if player == 'x':
            self.opponent = 'o'
        else:
            self.opponent = 'x'  
        
    def is_terminal(self, board):
        empty_moves = 0
        for row in board:
            empty_moves += row.count(self.empty_move)
        return empty_moves == 0

    def board_score(self, board, depth):
        """Board: a 2D sq array"""
        # Check win by row
        N = len(board)
        for row in range(N):
            if all(cell == self.player for cell in board[row]):
                return 10 - depth
            elif all(cell == self.opponent for cell in board[row]):
                return -10 
        # Check win by col
        for col in range(N):
            column = [row[col] for row in board]
            if all(cell == self.player for cell in column):
                return 10 - depth
            elif all(cell == self.opponent for cell in column):
                return -10
        # Check win by diagonals
        diagonal = [board[i][i] for i in range(N)]
        if all(cell == self.player for cell in diagonal):
            print("Win by diagonal")
            return 10 - depth
        elif all(cell == self.opponent for cell in diagonal):
            return -10 
        diagonal = [board[i][N - i - 1] for i in range(N)]
        if all(cell == self.player for cell in diagonal):
            print("Win by opp diagonal")
            return 10 - depth
        elif all(cell == self.opponent for cell in diagonal):
            print("Loss by opp diagonal")
            return -10
        return 0

    def best_move(self, board):
        b_move = (-1, -1)
        best_score = -10
        for i in range(self.N):
            for j in range(self.N):
                if board[i][j] == self.empty_move:
                    board[i][j] = self.player # Make the move
                    score = self.minimax(board, True, 1) # Find the score of the board after the move
                    if score > best_score:
                        b_move = (i, j)
                        best_score = score
                    # Undo the move for backtracking
                    board[i][j] = self.empty_move
        return b_move

    def minimax(self, board, isPlayer, depth=1):
        if self.is_terminal(board):
            return self.board_score(board, depth)
        
        if isPlayer:
            best_score = float('-inf')
            for i in range(self.N):
                for j in range(self.N):
                    if board[i][j] == self.empty_move:
                        board[i][j] = self.opponent # Make the move
                        score = self.minimax(board, False, depth+1) # Find the score of the board after the move
                        best_score = max(score, best_score)
                        board[i][j] = self.empty_move # Undo the move
            return best_score

        else:
            best_score = float('inf')
            for i in range(self.N):
                for j in range(self.N):
                    if board[i][j] == self.empty_move:
                        board[i][j] = self.player # Make the move
                        score = self.minimax(board, True, depth+1) # Find the score of the board after the move
                        best_score = min(score, best_score)
                        board[i][j] = self.empty_move # Undo the move
            return best_score
        

# t = TicTacToe(2, player='x')
# b = [['x', 'x'], ['x', 'o']] # win by row
# print(t.board_score(b))
# b = [['a', 'o'], ['a', 'o']] # opponent win by col
# print(t.board_score(b))
# b = [['x', 'o'], ['a', 'x']] # win by diagonal
# print(t.board_score(b))
# b = [['a', 'o'], ['o', 'x']] # opponent win by counter diagonal
# print(t.board_score(b))

t = TicTacToe(3, player='o')
b = [['o', 'x', 'o'], 
     ['-', 'x', 'x'], 
     ['o', '-', 'x']]
print(t.best_move(b))