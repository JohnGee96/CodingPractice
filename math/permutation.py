# Print the set of all possible permutation given a list of string

# Complexity O(n*n!) 

def permutation(S, prefix=""):
    if len(S) == 1:
        print(prefix + S[0])
        return
    else:
        for i in range(len(S)):
            permutation(S[:i] + S[i+1:], prefix + S[i]) # Create substring for recursion

# permutation(["1", "2", "3"], "")

def permutation_swap(S, swapIndex=0):
    if swapIndex == len(S):
        print("".join(S))
    else:
        for i in range(swapIndex, len(S)):
            S[i], S[swapIndex] = S[swapIndex], S[i]
            permutation_swap(S, swapIndex+1)
            S[i], S[swapIndex] = S[swapIndex], S[i] # Backtrack
        

permutation_swap(["1", "2", "3"])