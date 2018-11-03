# Given an unsorted array, return k largest element

# Algorithm:
# 1. max-heapify the array
# 2. Remove root k times

def k_largest(A, k):
    # Heapify A
    result = []
    for i in range(k):
        A = heapify(A)
        result.append(A.pop(0))
    return result


# Max heap
def heapify(A):
    # parent = i / 2
    # left child = 2i
    # right child = 2i + 1
    for i in range(len(A)):
        left_child = min(2 * i + 1, len(A) - 1)
        if A[left_child] > A[i]:
            A[left_child], A[i] = A[i], A[left_child]
        
        right_child = min(2 * i + 2, len(A) - 1)
        if A[right_child] > A[i]:
            A[right_child], A[i] = A[i], A[right_child]

        # if change root, propagate the change up
        parent = i // 2
        while A[i] > A[parent]:
            A[parent], A[i] = A[i], A[parent]
            i = parent 
            parent = i // 2
    return A

A = [1,2,10,4,0,11]
A.reverse()
# print(A)
# print(heapify(A))
print(k_largest(A, 3))
