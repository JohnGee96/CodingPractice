# Given an array, find the contiguous subarray with the largest sum.

# Kadane's Algorithm
# Max(max+i, i)

def max_sum_subarray(A):
    head = tail = 0
    start = end = 0
    global_max = A[0]
    max_sum = A[0]
    for i in range(len(A)):
        if A[i] >= max_sum + A[i]:
            tail = i
            head = i + 1
            max_sum = A[i]
        else:
            max_sum += A[i]
            head += 1

        if max_sum > global_max:
            global_max = max_sum
            start = tail
            end = head
    
    return A[start:end]

# print(max_sum_subarray([-4, 2, -5, 1, 2, 3, 6, -5, 1]))

print(max_sum_subarray([110, -50, 3, -50, 5, 112]))