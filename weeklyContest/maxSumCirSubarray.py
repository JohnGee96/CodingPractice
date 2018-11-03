# Maximum Sum Circular Subarray

# Given a circular array C of integers represented by A, 
# find the maximum possible sum of a non-empty subarray of C.
# Here, a circular array means the end of the array connects to the beginning of the array.  

# (Formally, C[i] = A[i] when 0 <= i < A.length, and C[i+A.length] = C[i] when i >= 0.)

# Also, a subarray may only include each element of the fixed buffer A at most once.  

# (Formally, for a subarray C[i], C[i+1], ..., C[j], there does not exist i <= k1, k2 <= j with k1 % A.length = k2 % A.length.)

# Input: [5,-3,5]
# Output: 10
# Explanation: Subarray [5,5] has maximum sum 5 + 5 = 10

# The max subarray circular sum equals to
# max(the max subarray sum, the total sum - the min subarray sum)
# One corner case: If all number are negative, return the maximum one, (which equals to the max subarray sum)


def maxSubarraySumCircular(A):
    # Kadane's algorithm
    max_sum, min_sum, cur_max, cur_min, total = -float('inf'), float('inf'), 0, 0, 0
    for a in A:
        cur_max = max(cur_max + a, a)
        max_sum = max(cur_max, max_sum)
        cur_min = min(cur_min + a, a)
        min_sum = min(cur_min, min_sum)
        total += a
    return max(max_sum, total - min_sum) if max_sum > 0 else max_sum # Resolve corner case 



def maxSubarraySumCircularDP(A):
        """
        :type A: List[int]
        :rtype: int
        """
        # deal with the case when window size is 1 or equal to size of array
        max_sum = max(max(A), sum(A))
        array_size = len(A)
        # initialize the table
        dp_table = [[A[i] for i in range(array_size)] for _ in range(array_size)]
        
        # We ignore the case when window size is 1 or is equal to size of array
        for windowSize in range(1, array_size - 1):
            left = 0
            while left < array_size:
                left %= array_size
                right = left + windowSize
                prev_sum = dp_table[left][(right - 1) % array_size]
                cur_sum = prev_sum + A[right % array_size]
                # update table
                dp_table[left][right % array_size] = cur_sum
                # update global sum
                max_sum = max(cur_sum, max_sum)
                # increment ptr
                left += 1
        return max_sum

    
# 0 1 n
# n 1 3
# n n 2

print(maxSubarraySumCircular([-1,-2,-3,-4,-5]))
            