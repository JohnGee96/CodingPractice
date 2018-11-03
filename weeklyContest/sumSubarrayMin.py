# Problem: 
# Given an array of integers A, find the sum of min(B), 
# where B ranges over every (contiguous) subarray of A.
# https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/C++JavaPython-Stack-Solution?page=2

# Example 1:
# Input: [3,1,2,4]
# Output: 17
# Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
# Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.

# I use a monotonous increasing stack to store the left boundary and right boundary where a number is the minimal number in the sub-array

# e.g. given [3,1,2,4],
# For 3, the boudary is: | 3 | ...
# For 1, the boudray is: | 3 1 2 4 |
# For 2, the boudray is: ... | 2 4 |
# For 4, the boudary is: ... | 4 |

# The times a number n occurs in the minimums is |left_bounday-indexof(n)| * |right_bounday-indexof(n)|

# The total sum is sum([n * |left_bounday - indexof(n)| * |right_bounday - indexof(n)| for n in array])

# After a number n pops out from an increasing stack, the current stack top is n's left_boundary, the number forcing n to pop is n's right_boundary.

# A tricky here is to add MIN_VALUE at the head and end.
def sumSubarrayMins(A):
    """
    :type A: List[int]
    :rtype: int
    """
    # s = 0
    # for i in range(len(A)):
    #     left = right = i
    #     while left - 1 > -1 and A[left - 1] > A[i]:
    #         left -= 1
    #     while right + 1 < len(A) and A[right + 1] >= A[i]:
    #         right += 1
    #     print(left, right)
    #     s = s + (A[i] * (i - left + 1) * (right - i + 1)) % (1e9 + 7)
    # return s

    res = 0
    stack = []  # increasing
    # A = [float('-inf')] + A + [float('-inf')]
    for i, n in enumerate(A):
        while stack and A[stack[-1]] > n:
            cur = stack.pop()
            print("Pops: ", cur, "(value: ", A[cur],  ") by: ", n)
            print(stack)
            print('\n')
            res += A[cur] * (i - cur) * (cur - stack[-1]) 
        stack.append(i)
        print("appended:", i)
        print(stack)
    return res % (10**9 + 7)

x = [3,1,2,4]
print(x)
print(sumSubarrayMins(x))
# print(sumSubarrayMins([71,55,82,55]))



