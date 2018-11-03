# Solve N-Queens problem
# Given a chess board of size N x N, 
# determine how many ways N queens can be placed
# on this board so that no two queens attack each other.

# One very simple solution is to find all configurations with 
# all possible placements of n-queens on the chess board 
# and then determine for every configuration if it is valid or not. 
# But it is very expensive, and we don't need it. 
# It will be equivalent to choose N such configurations 
# from NxN configurations. It is not required to try all 
# possible configurations. 
# We know that if we place one queen in a row, 
# we can't place another queen in the same row, 
# so a lot of configurations can be pruned very easily.
#  We'll prune unnecessary configurations and use backtracking 
# to try another configuration.

# Backtracking algorithm to solve the n-queens problem is very
#  similar to a depth-first search of a tree. 
# Below is the algorithm.

# Place a queen in the first column of the first row
# Now place a queen in first such column of 2nd row where 
# placement is permissible i.e. current queen is not being 
# attacked by any queen already on board. 
# If no such column is found, we'll backtrack to the
# previous row and try to place the queen in next column
# of that row.
# We'll continue this until we reach the last row of the board.
# When we have successfully placed a queen in the last row, 
# that is a solution. After finding a solution, 
# we'll backtrack to the previous row to find the next solution. 
# We'll try to find another column in the previous row where 
# placement is permissible.

def solve_n_queens(n):
    return

def solve_n_queens_recur(n, i, j, board):
    
    return

def is_valid_pos(i, j, board):
    if 
    return


def test_n_queens(n, board):
    return