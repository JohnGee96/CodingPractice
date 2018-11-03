# You have a boutique that specializes in words that don't 
# have adjacent matching characters. Bobby, a competitor, 
# has decided to get out of the word business altogether 
# and you have bought his inventory. Your idea is to 
# modify his inventory of words so they are suitable for 
# sale in your store. 

# To do this, you find all adjacent pairs of matching characters 
# and replace one of the characters with a different one. 

# Determine the minimum number of characters that must be 
# replaced to make a salable word.

# For example, words = [add, boook, break]. Change 'd' in 'add' 
# and 'o' in boook. 




# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY words as parameter.
#

def minimalOperations(words):
    result = []
    for word in words:
        result.append(minReplaceWord(word))
    return result

def minReplaceWord(word):
    traverse_len = len(word)
    num_replace = 0
    if traverse_len == 1:
        return 0
    elif traverse_len == 2:
        return int(word[0] == word[1]) # Corner case: only two-char word
   
    head, tail = 1, 0
    while head < traverse_len:
        if word[head] == word[tail]:
            head += 1
        else:
            if head != tail + 1: # There's repetition
                num_replace += (head - tail) // 2
                tail = head - 1
            head += 1
            tail += 1
        if head == traverse_len - 1 and word[head] == word[tail]: # Corner case
            num_replace += (head - tail + 1) // 2 # Add one because min repetition is 2 
    return num_replace


# print(minimalOperations(["bb"]))
print(minimalOperations(["5", "ab", "abab"]))
print(minimalOperations(["aa", "aaa", "aab", "abb", "abaaaba", "abbbabbbbb"]))