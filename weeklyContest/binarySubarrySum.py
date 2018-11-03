# 930. Binary Subarrays With Sum
# In an array A of 0s and 1s, how many non-empty 
# subarrays have sum S?

# Example 1:

# Input: A = [1,0,1,0,1], S = 2
# Output: 4
# Explanation: 
# The 4 subarrays are bolded below:
# [1,0,1,0,1]
# [1,0,1,0,1]
# [1,0,1,0,1]
# [1,0,1,0,1]

# Solution 1. Brute force. We just need two loops (i, j) 
# and test if SUM[i, j] = k. Time complexity O(n^2), 
# Space complexity O(1).

# Solution 2. From solution 1, we know the key to solve 
# this problem is SUM[i, j]. So if we know SUM[0, i - 1] 
# and SUM[0, j], then we can easily get SUM[i, j].
# To achieve this, we just need to go through the array, 
# calculate the current sum and save number of all seen 
# PreSum to a HashMap. 
# Time complexity O(n), Space complexity O(n).

from collections import Counter

def numSubarraysWithSum( A, S):
    c = Counter({0: 1})
    psum = res = 0
    for i in A:
        psum += i
        res += c[psum - S]
        c[psum] += 1
    return res

# print(numSubarraysWithSum([1,0,1,0,1], 2))
print(numSubarraysWithSum([0,0,1,0,1,0], 2))