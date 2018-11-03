# 926. Flip String to Monotone Increasing
# A string of '0's and '1's is monotone 
# increasing if it consists of some number of
# '0's (possibly 0), followed by some number of '1's 
# (also possibly 0.)
# We are given a string S of '0's and '1's, 
# and we may flip any '0' to a '1' or a '1' to a '0'.
# Return the minimum number of flips to make 
# S monotone increasing.

# Example 1:

# Input: "00110"
# Output: 1
# Explanation: We flip the last digit to get 00111.
# Example 2:

# Input: "010110"
# Output: 2
# Explanation: We flip to get 011111, or alternatively 000111.
# Example 3:

# Input: "00011000"
# Output: 2
# Explanation: We flip to get 00000000.

# Algorithm 1
# At each position i, keep track of 0's left of i and 1's right of i
# The number of flip at i postion = left[0] + right[0]
# Return the of position among all i's

# Algorithm 2
# Skip 0's until we encounter the first 1.
# Keep track of number of 1's in onesCount (Prefix).
# Any 0 that comes after we encounter 1 can be a potential candidate for flip. Keep track of it in flipCount.
# If flipCount exceeds oneCount - (Prefix 1's flipped to 0's)
# a. Then we are trying to flip more 0's (suffix) than number of 1's (prefix) we have.
# b. Its better to flip the 1's instea

def minFlipMonoIncr(s):
    left1 = right0 = 0
    # Find number of 1s 
    for c in s:
        right0 += (c == '0')
        
    minFlip = right0
    for i in range(len(s)):
        left1 += (s[i] == '1')
        right0 -= (s[i] == '0')
        minFlip = min(minFlip, left1 + right0)
    return minFlip
    
print(minFlipMonoIncr("010110"))