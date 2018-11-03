# Given a string find all substrings that are palindromes.
# Ex: aabbbaa - aa, bb, aa, bbb, aabbbaa, abbba

def palindrome_substr(S):
    palindromes = []
    for i in range(len(S)):
        j, k = i - 1, i + 1
        find_palindrome(S, j, k, palindromes)
        j = i
        find_palindrome(S, j, k, palindromes)
    return palindromes

def find_palindrome(S, j, k, palindromes):
    p = ""
    while j >= 0 and k < len(S) and S[j] == S[k] :
        p = S[j:k+1]
        palindromes.append(p)
        j -= 1
        k += 1
    return palindromes

print(palindrome_substr("aabbbaa"))