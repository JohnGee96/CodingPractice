# Given coins denominations and total amount, 
# find out the number of ways to make the change.

# To count the total number of solutions, we can divide all set solutions into two sets.
# 1) Solutions that do not contain mth coin (or Sm).
# 2) Solutions that contain at least one Sm.
#  count(S[], m, n) = count(S[], m-1, n) and count(S[], m, n-Sm).

def coin_change(amount, denomin):
    return coin_change_recur(amount, denomin, len(denomin))

def coin_change_recur(amount, denomin, m):
    if amount < 0:
        return 0
    elif amount == 0:
        return 1
    elif (m < 1 and amount > 0):
        return 0 # No coins left and there is remaining amount, no solution
    else:
        return coin_change_recur(amount, denomin, m - 1) \
         + coin_change_recur(amount - denomin[m - 1], denomin,  m)

def coin_change_dp(amount, denomin):
    dp_table = [0] * (amount + 1)
    dp_table[0] = 1
    for d in denomin:
        for i in range(d, amount):
            dp_table[i] += dp_table[i - d]
    return dp_table[-1]

print(coin_change(7, [1, 2, 5]))