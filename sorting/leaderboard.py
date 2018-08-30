# Problem Link:
# https://www.hackerrank.com/challenges/climbing-the-leaderboard/problem

# !/bin/python3
import math
import os
import random
import re
import sys
from bisect import bisect_right

# Complete the climbingLeaderboard function below.
def climbingLeaderboard(scores, alice):
    alice_rank = []
    rank = list(sorted(set(scores)))
    for alice_score in alice:
        insert_index = bisect_right(rank, alice_score)
        print(alice_score, insert_index)
        alice_rank.append(len(rank) - insert_index + 1)

    return alice_rank
        
            

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    scores_count = int(input())

    scores = list(map(int, input().rstrip().split()))

    alice_count = int(input())

    alice = list(map(int, input().rstrip().split()))

    result = climbingLeaderboard(scores, alice)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
