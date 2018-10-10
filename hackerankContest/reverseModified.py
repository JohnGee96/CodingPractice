# Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

# Example 1:

# Input: "ab-cd"
# Output: "dc-ba"

def reverseOnlyLetters(S):
    """
    :type S: str
    :rtype: str
    """
    left = 0
    right = len(S) - 1
    S_rev = list(S)
    while left < right:
        print(left, right)
        if S[left].isalpha() and S[right].isalpha():
            temp = S_rev[left]
            S_rev[left] = S_rev[right]
            S_rev[right] = temp
            right -= 1
            left += 1
        elif S_rev[left].isalpha():
            right -= 1
        else:
            left += 1
    return ''.join(S_rev)


print(reverseOnlyLetters("ab-cd"))
print(reverseOnlyLetters("a-bC-dEf-ghIj"))
# print(list("123"))