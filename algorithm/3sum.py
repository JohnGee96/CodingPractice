# Sum of Three Values
# Given an array of integers and a value, 
# determine if there are any three integers 
# in the array that sum equal to the given value.

from collections import Counter

def two_sum(counter, target):
    for value in counter.keys():
        counterpart = target - value
        if counterpart in counter:
            return True
    return False

def find_sum_of_three(arr, required_sum):
    c = Counter(arr)
    for a in arr:
        target = required_sum - a
        if two_sum(c, target):
            return True
    return False


def test():
    arr = [-25, -10, -7, -3, 2, 4, 8, 10]
    print(find_sum_of_three(arr, -8))
    print(find_sum_of_three(arr, -25))
    print(find_sum_of_three(arr, 0))
    print(find_sum_of_three(arr, -42) )
    print(find_sum_of_three(arr, 22) )
    print(find_sum_of_three(arr, -7))
    print(find_sum_of_three(arr, -3) )
    print(find_sum_of_three(arr, 2) )
    print(find_sum_of_three(arr, 4) )
    print(find_sum_of_three(arr, 8) )
    print(find_sum_of_three(arr, 7) )
    print(find_sum_of_three(arr, 1))
  
test()

print(find_sum_of_three([-25, -10, -7, -3, 2, 4, 8, 10],1))

