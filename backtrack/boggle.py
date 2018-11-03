# Boggle
# Given an NxN grid of characters and a dictionary, 
# find all words which can be made from the characters 
# in grid and present in the given dictionary. 

# A word can start and end at any character in the grid. 
# Next character must be adjacent to previous character 
# in any of the directions i.e. up, down, left, right 
# and diagonal. Character at each position in grid can be
#  used only once while making a word.

# Runtime Complexity
# Exponential, O(N^n).

# where 'N' is the dimension of the grid.

# The recurrence relation for time complexity is

# T(N) = N^2 T(N-1)

# Memory Complexity
# Quadratic, O(N2).

# where 'N' is the dimension of the grid. 
# Recursive solution will consume memory on the stack as well.
from functools import reduce


class Boggle(object):
    #code assumes that both dimensions of grid are same
    def __init__(self, grid, dictionary):
        self.grid = grid
        self.N = len(grid)
        self.dictionary = dictionary
        self.state = [[False for x in range(len(grid))] \
                    for y in range(len(grid))]
        self.words = set([])


    def find_all_words(self):
        # search every char in the grid
        for i in range(self.N):
            for j in range(self.N):
                cur_word = ""
                self.find_all_words_rec(i, j, cur_word)
        return self.words
    
    def isPrefix(self, prefix):
        return reduce(lambda result, word: result or (prefix in word), self.dictionary, False)
    
    def isInDict(self, word):
        return word in self.dictionary

    def find_neighbor(self, i, j):
        # neighbors are top, down, left, right and diagonal
        all_neighbors = []
        row_min, row_max = max(0, i-1), min(self.N, i+2)
        col_min, col_max = max(0, j-1), min(self.N, j+2)
        for x in range(row_min, row_max):
            for y in range(col_min, col_max):
                if x==i and y==j:
                    continue
                if self.state[x][y] == False:
                    all_neighbors.append((x, y))
        return all_neighbors

    def find_all_words_rec(self, i, j, cur_word):
        neighbors = self.find_neighbor(i,j)

        cur_word += self.grid[i][j]
        print(cur_word)
        if self.isInDict(cur_word):
            self.words.add(cur_word)
        
        if self.isPrefix(cur_word):
            self.state[i][j] = True
            for n in neighbors:
                x, y = n
                self.find_all_words_rec(x, y, cur_word)
            self.state[i][j] = False # Revert to the previous state for backtracking
        return


grid = [
    ['c', 'a', 't'],
    ['r', 'r', 'e'],
    ['t', 'o', 'n']
  ]

dictionary = set(["cat", "cater", "cartoon", 
"toon", "moon", "not", "tone", "apple", "ton", "art"])

b = Boggle(grid, dictionary)
words = b.find_all_words()

for w in words:
    print(w, end=' ')

# b.find_all_words()
# print(b.find_neighbor(0,1))

