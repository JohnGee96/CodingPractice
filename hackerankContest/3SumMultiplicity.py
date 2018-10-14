# 923. 3Sum With Multiplicity
# Given an integer array A, and an integer target, 
# return the number of tuples i, j, k  such that i < j < k 
# and A[i] + A[j] + A[k] == target.
# As the answer can be very large, return it modulo 10^9 + 7.

# Example 1:

# Input: A = [1,1,2,2,3,3,4,4,5,5], target = 8
# Output: 20
# Explanation: 
# Enumerating by the values (A[i], A[j], A[k]):
# (1, 2, 5) occurs 8 times;
# (1, 3, 4) occurs 8 times;
# (2, 2, 3) occurs 2 times;
# (2, 3, 3) occurs 2 times.

# Example 2:

# Input: A = [1,1,2,2,2,2], target = 5
# Output: 12
# Explanation: 
# A[i] = 1, A[j] = A[k] = 2 occurs 12 times:
# We choose one 1 from [1,1] in 2 ways,
# and two 2s from [2,2,2,2] in 6 ways.
 
# Note:
# 3 <= A.length <= 3000
# 0 <= A[i] <= 100
# 0 <= target <= 300


# Let count[x] be the number of times that x occurs in A. For every x+y+z == target, we can try to count the correct contribution to the answer. There are a few cases:

# If x, y, and z are all different, then the contribution is count[x] * count[y] * count[z].
# If x == y != z, the contribution is [count[x] choose 2] * count[z]
# If x != y == z, the contribution is count[x] * [count[y] choose 2]
# If x == y == z, the contribution is [count[x] choose 3]

from math import factorial
from collections import Counter

def findCombinations(d, target, minimum):
    total_comb = 0
    for k in d.keys():
        if k < minimum:
            continue
        counterpart = target - k
        if counterpart in d:
            if minimum < k < counterpart:
                print(minimum, k, counterpart, 'total:', d[minimum] * d[k] * d[counterpart])
                total_comb += d[minimum] * d[k] * d[counterpart]
            elif minimum == k < counterpart:
                print(minimum, k, counterpart, 'total:', d[k] * (d[k] - 1) / 2 * d[counterpart])
                total_comb += d[k] * (d[k] - 1) / 2 * d[counterpart]
            elif minimum < k == counterpart:
                print(minimum, k, counterpart, 'total:', d[minimum] * d[k] * (d[k] - 1) / 2)
                total_comb += d[minimum] * d[k] * (d[k] - 1) / 2
            elif minimum == k == counterpart:
                print(minimum, k, counterpart, d[k] * (d[k] - 1) * (d[k] - 2) / 3 )
                total_comb += d[k] * (d[k] - 1) * (d[k] - 2) / 6
    return total_comb

def threeSumMulti(A, target):
    d = Counter(A)
    total_comb = 0
    for k in d.keys():
        counterpart = target - k
        if counterpart >= k:
            total_comb += findCombinations(d, counterpart, k)
    return total_comb

print(threeSumMulti([0,0,0], 0))