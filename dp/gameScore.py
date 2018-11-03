# Find number of ways a player can score 'n' runs
# Imagine a game (like baseball) where a player can 
# score 1, 2 or 4 runs. Given a score "n", find the 
# total number of ways score "n" can be reached

# Scoring options are 1, 2, 4
# Recursion relationship
# S(n) = S(n−1) + S(n−2) + S(n−4)

SCORE_OPTION = [1,2,4]
def scoring_options(n):
    if n < 0:
        return 0
    elif n == 1 or n == 0:
        return 1
    elif n == 2:
        return 2
    else:
        cnt = 0
        for score in SCORE_OPTION:
            cnt += scoring_options(n - score)
        return cnt

def scoring_options_dp(n):
    if n < 1:
        return 0
    else:
        max_lookback = max(SCORE_OPTION)
        scores = [0] * max_lookback
        scores[-1] = 1 # 1 way to sum to 1
        for _ in range(n):
            s = scores[3] + scores[2] + scores[0]
            for i in range(1, max_lookback):
                scores[i - 1] = scores[i] # cache all prev 4 iterations
            scores[max_lookback - 1] = s
        return scores[max_lookback - 1]

def print_score_options(n):
    print_score_options_recur(n, [], 0)

def print_score_options_recur(n, comb, cur_sum):
    if cur_sum == n:
        print(comb)
    elif cur_sum > n:
        return
    remain = n - cur_sum        
    if remain == 2:
        options = [1,2]
    elif remain == 1:
        options = [1]
    else:
        options = [1,2,4]
    for score in options:
        comb.append(score)
        print_score_options_recur(n, comb, cur_sum + score)
        comb.pop()
 
n = 4
print(scoring_options(n))
print(scoring_options_dp(n))
print_score_options(n)