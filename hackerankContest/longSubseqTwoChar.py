# Problem: finding longest subsequence with 2 or less repeating character
# https://leetcode.com/contest/weekly-contest-102/problems/fruit-into-baskets/

from collections import defaultdict

def totalFruit(tree):
    """
    :type tree: List[int]
    :rtype: int
    """
    head, result, d = 0, 0, defaultdict(int)
    d[tree[0]] = 0
    for i in range(len(tree)):
        d[tree[i]] += 1
        while len(d) > 2:
            d[tree[head]] -= 1
            if d[tree[head]] == 0:
                d.pop(tree[head])
            head += 1
        result = max(result, i - head + 1)
    return result


tree1 = [1,0,1,4,1,4,1,2,3]
tree2 = [1,3,1]
print(totalFruit(tree1))
    

# def totalFruit(tree):
#     """
#     :type tree: List[int]
#     :rtype: int
#     # """
#     # Longest subsequence of two characters
#     glob_cnt = 0
#     head = 0
#     tail = 0
#     f1 = tree[0]
#     while tail < len(tree):
#         if tree[tail] == f1:
#             tail += 1
#         else:
#             f2 = tree[tail] #initialize the second type
#             break

#     while tail < len(tree):
#         if tree[tail] != f1 and tree[tail] != f2:
#             # Compare current count with global count
#             if tail - head > glob_cnt:
#                 print(head, tail)
#                 glob_cnt = tail - head
#             f1 = tree[tail]
#             f2 = tree[tail - 1] # store the last fruit
#             head = tail - 1
#             while head > -1: # move back head
#                 if tree[head - 1] == f2:
#                     head -= 1
#                 else:
#                     break
#         tail += 1
#     return max(glob_cnt, tail - head)