# Find an efficient algorithm to find maximum sum of 
# a subsequence in an array such that no consecutive 
# elements are part of this subsequence.

# Kadane's Algorithm with a twist:
# Iterate over the entire input array and 
# in every iteration pick the maximum of these two values:
# Max Sum of the last iteration
# Max Sum of second last iteration + current iteration index.

def max_sum_nonadj(A):
    global_sum = A[0]
    prev_sum = float('-inf')
    pprev_sum = float('-inf')
    for i in range(len(A)):
        if i >= 1:
            cur_sum = max(prev_sum, A[i] + pprev_sum)
            pprev_sum = prev_sum
        else:
            cur_sum = max(A[i], prev_sum)
        global_sum = max(global_sum, cur_sum)
        prev_sum = cur_sum
        

    return global_sum

print(max_sum_nonadj([1, -1, 6, -4, 2, 100]))