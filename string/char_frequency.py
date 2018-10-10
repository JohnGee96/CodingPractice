# Given a string, sort it in decreasing order based on the frequency of characters.

# Input:
# "Aabb"

# Output:
# "bbAa"

from functools import reduce
from collections import Counter

def frequencySort(s):
    cnt = Counter(s)
    # s = ''
    # for c, count in cnt.most_common():
    #     s += c * count
    # return s
    return reduce(lambda a, b: a + b[1]*b[0], cnt.most_common(), '')

print(frequencySort('fAsaeacccb'))