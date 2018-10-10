# Number of Music Playlists

# Your music player contains N different songs and 
# she wants to listen to L (not necessarily different) 
# songs during your trip.  You create a playlist so that:

# Every song is played at least once
# A song can only be played again only if K other songs have been played
# Return the number of possible playlists. 
# As the answer can be very large, return it modulo 10^9 + 7


# Example 1:

# Input: N = 3, L = 3, K = 1
# Output: 6
# Explanation: There are 6 possible playlists. [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1].
# Example 2:

# Input: N = 2, L = 3, K = 0
# Output: 6
# Explanation: There are 6 possible playlists. [1, 1, 2], [1, 2, 1], [2, 1, 1], [2, 2, 1], [2, 1, 2], [1, 2, 2]
# Example 3:

# Input: N = 2, L = 3, K = 1
# Output: 2
# Explanation: There are 2 possible playlists. [1, 2, 1], [2, 1, 2]


# RESTRICTIONS: 0 <= K < N <= L <= 100

# SOLUTION from lee215: 

# F(N,L,K) = F(N - 1, L - 1, K) * N + F(N, L - 1, K) * (N - K)

# F(N - 1, L - 1, K)
# If only N - 1 in the L - 1 first songs.
# We need to put the rest one at the end of music list.
# Any song can be this last song, so there are N possible combinations.

# F(N, L - 1, K)
# If already N in the L - 1 first songs.
# We can put any song at the end of music list,
# but it should be different from K last song.
# We have N - K choices.

# Time Complexity:
# O((L-K)(N-K))

# [ ... ]      1 
#   L=3        2   N=3      K=0
#              3

# [1 .. ]      1
#   L=2        2   N=2      K=1
#              3

# [1 2 .. ]      
#   L=1           N=1      K=1
#              3



# [1 2 3 1 2]  N = [1 2 3]  k = 2
#              N = 3
#   L = 2

#             +

# [1 2 3 _ _]  N = [2 3]  k = 2
#              N = 0
#   L = 2

# [1 ] [2 ] [3 ]

# [1 2 ] [1 3] [2 1 ] [2 3] [3 1] [3 2]

from functools import lru_cache
from math import factorial

def numMusicPlaylists(N, L, K):
    # Decorator to wrap a function with a memoizing callable 
    # that saves up to the maxsize most recent calls. 
    # It can save time when an expensive or I/O bound function 
    # is periodically called with the same arguments.
    # If maxsize is set to None, the LRU feature is disabled 
    # and the cache can grow without bound. 
    # The LRU feature performs best when maxsize is a power-of-two.
    @lru_cache(None)
    def dp(n, l):
        if l == 0:
            return (n == 0)
        return dp(n - 1, l - 1) * (N - n + 1) + dp(n, l - 1) * max(n - K, 0)
    return dp(N, L) % (10**9+7)


def numMusicPlaylists_table(self, N, L, K):
    dp = [[0 for i in range(L + 1)] for j in range(N + 1)]
    for i in range(K + 1, N + 1):
        for j in range(i, L + 1):
            if i == j or i == K + 1:
                dp[i][j] = factorial(i)
            else:
                dp[i][j] = dp[i - 1][j - 1] * i + dp[i][j - 1] * (i - K)
    return dp[N][L] % (10**9 + 7)