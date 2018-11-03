# 927. Three Equal Parts
# Given an array A of 0s and 1s, divide the array into 
# 3 non-empty parts such that all of these parts represent 
# the same binary value.
# If it is possible, return any [i, j] with i+1 < j, such that:

# A[0], A[1], ..., A[i] is the first part;
# A[i+1], A[i+2], ..., A[j-1] is the second part, and
# A[j], A[j+1], ..., A[A.length - 1] is the third part.
# All three parts have equal binary value.
# If it is not possible, return [-1, -1].

# Note that the entire part is used when considering what
# binary value it represents.  
# For example, [1,1,0] represents 6 in decimal, not 3.
# Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.

# Example 1:
# Input: [1,0,1,0,1]
# Output: [0,3]
# Example 2:

# Input: [1,1,0,1,1]
# Output: [-1,-1]
 
# Note:
# 3 <= A.length <= 30000
# A[i] == 0 or A[i] == 1

# Algorithm
# If #1's == 0 return [0, 1]
# If #1's % 3 != 0, there is NO WAY to distribute evenly among three parts: [-1, -1]
# This means each part must have exactly total_1's / 3
#   a. Loop through A until seeing (total_1's / 3) 'this many 1's (this is where the first index, e1, is)
#   b. Continue to loop through A until seeing (total_1's / 3) 'this many 1's (this is where the 2nd index, e2, is)
# Now, we need to locate and verify if all three segments are equal, and 
#   a. Three ptr: s1, s2, s3 and initialize them at the first 1 in their responding segment 
#   b. Increment  s1, s2 and s3 if A[s1] == A[s2] == A[s3]
#   c. If s3 == len(A) return [s1 - 1 , s2]
#   d. Else all three segments are NOT equal so return [-1, -1]

# def isEqPart(p1, p2):
#     ptr1 = ptr2 = 0
#     p1_len = len(p1)
#     p2_len = len(p2)
#     while ptr1 < p1_len and ptr2 < p2_len:
#         if p1[ptr1] == p2[ptr2]:
#             ptr1 += 1
#             ptr2 += 1
#         elif p1[ptr1] == 0:
#             ptr1 += 1
#         else:
#             ptr2 += 1
#     if ptr1 == len(p1) and ptr2 == len(p2):
#         return True
#     else:
#         return False
    
# print(isEqPart([1,0,1], [1,0,1]))   # T
# print(isEqPart([1], [1]))           # T
# print(isEqPart([0,0,1], [1]))       # T
# print(isEqPart([1,1,1], [1,0,1]))   # F
# print(isEqPart([1,0,0], [1]))       # F
# print(isEqPart([0,1,0], [1]))       # F
# print(isEqPart([1,0,0], [1]))       # F
            
def threeEqParts(A):
    """
    :type A: List[int]
    :rtype: List[int]
    """
    numOnes = A.count(1)
    if numOnes == 0:
        return [0, len(A) - 1]
    elif numOnes % 3 != 0:
        return [-1, -1]
    else:
        oneCount = 0
        numOneSegment = numOnes / 3
        # Find where the 3 segments will be located
        for i in range(len(A)):
            if A[i] == 1:
                if oneCount == 0:
                    s1 = i # Initialize 1st segment pointer:
                if oneCount == numOneSegment:
                    s2 = i # Initialize 2nd segment pointer:
                if oneCount == 2*numOneSegment:
                    s3 = i # Initialize 3rd segment pointer:
                oneCount += 1
        # Verify if all three segments are equal
        while s3 < len(A) and A[s1] == A[s2] == A[s3]:
            s1 += 1
            s2 += 1
            s3 += 1
        if s3 == len(A):
            return [s1 - 1, s2]
        else:
            return [-1, -1]


print(threeEqParts([1,0,0,1,1]))