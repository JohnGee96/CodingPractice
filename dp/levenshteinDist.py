# Given two strings, compute the Levenshtein distance (edit distance)
# between them i.e. the minimum number of edits required 
# to convert one string into the other.

# For example, the Levenshtein distance between 
# "kitten" and "sitting" is 3.

# Algorithm:
# Let i and j be the index of str a and b respectively
# If a or b is empty, return max(len(a), len(b))
# lev(i, j) = min(lev(i-1, j)+1, lev(i, j-1)+1, lev(i-1, j-1)+cost)
#      where cost = 0 if a[i] == a[j] else 1

def lev_dist(A, B):
    if len(A) == 0 or len(B) == 0:
        return max(len(A), len(B))
    # Initialize table
    dp_table = [[0] * (len(B) + 1) for _ in range(len(A) + 1)]
    dp_table[0] = [i for i in range(0, len(B) + 1)] # Init 1st row
    for i in range(len(dp_table)): dp_table[i][0] = i # Init 1st col
    
    for i in range(1, len(A) + 1):
        for j in range(1, len(B) + 1):
            cost = A[i - 1] != B[j - 1]
            dp_table[i][j] = min(dp_table[i - 1][j] + 1, 
                                 dp_table[i][j - 1] + 1 , 
                                 dp_table[i - 1][j - 1] + cost)


    return dp_table[len(A)][len(B)]

print(lev_dist("kitten", "sitting" ))