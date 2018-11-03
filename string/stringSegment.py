# Given a dictionary of words and an input string
# tell whether the input string can be completely 
# segmented into dictionary words.
# Extension: return the list of all possible words

# Example:
# Dictionary: {follow, follower, low, lower, now, on}
# Input: follower onow
# follow, lower, follower, low, on, now

# Algorithm:
# n = length of input string
# for i = 0 to n-1
#     firstword = substring (input string from index [0 , i] )
#     secondword = substring (input string from index [i+1 , n-1] )
#     if dictionary has firstword
#         if secondword is in dictionary OR second word is of zero length, then return true
#         recursively call this method with secondword as input and return true if it can be segmented

def segment_string(s, d):
    words = []
    for i in range(len(s)):
        tail = s[i:]
        head = s[:i]
        if head in d:
            words.append(head)
            if tail in d or tail == '':
                words.append(tail)
                return words
            words = words + segment_string(tail, d)

    return words


d = {'follow', 'fol', 'follower', 'low', 'lower', 'on', 'now'}
input = 'followeronow'
print(segment_string(input, d))