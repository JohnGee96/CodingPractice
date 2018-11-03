# 931. Minimum Falling Path Sum

# Given a square array of integers A, we want the 
# minimum sum of a falling path through A.

# A falling path starts at any element in the first row, 
# and chooses one element from each row.  
# The next row's choice must be in a column that is different from
# the previous row's column by at most one.

# Example 1:

# Input: [[1,2,3],[4,5,6],[7,8,9]]
# Output: 12
# Explanation: 
# The possible falling paths are:
# [1,4,7], [1,4,8], [1,5,7], [1,5,8], [1,5,9]
# [2,4,7], [2,4,8], [2,5,7], [2,5,8], [2,5,9], [2,6,8], [2,6,9]
# [3,5,7], [3,5,8], [3,5,9], [3,6,8], [3,6,9]
# The falling path with the smallest sum is [1,4,7],
# so the answer is 12.

# Algorithm
# The minimum path to get to element A[i][j] is the 
# minimum of 
# 1. A[i - 1][j - 1],
# 2. A[i - 1][j]
# 3. A[i - 1][j + 1].
# Starting from row 1

def min_fall_path(A):
    for i in range(1, len(A)):
        for j in range(len(A)):
            topLeft = A[max(i - 1, 0)][max(j - 1, 0)]
            topMid = A[max(i - 1, 0)][j]
            topRight = A[max(i - 1, 0)][min(j + 1, len(A) - 1)]
            A[i][j] += min(topLeft, topMid, topRight)
    return min(A[-1])

A = [[1,2,3],[4,5,6],[7,8,9]]
print(min_fall_path(A))