# Braces in a string are considered to be balanced if 
# the following criteria are met:

# All braces must be closed. 
# Braces comes in pairs of the form (), {} and []
# In any nested braces, the braces between any pair must be closed.

# Input:
# {}[]()
# {[}]}

# Output:
# YES
# NO


def braces(values):
    result = []
    for v in values:
        result.append(isBalancedBraces(v))
    return result

def isBalancedBraces(S):
    if len(S) == 1:
        return "NO"
    stack = []
    matching_d = {'(':')', '[':']', '{':'}'}
    for s in S:
        if s == '(' or s == '[' or s == '{':
            stack.append(s)
        else:
            if stack:
                braces_to_match = stack.pop()
                if matching_d[braces_to_match] != s:
                    return "NO"
            else:
                return "NO" #False if we encounter any right closing braces when stack empty
    if stack:
        return "NO"
    else:
        return "YES"

print(braces(["{}[]()", "{{[](([()()]))}}"]))
print(braces(["{[}]}", "[", "]", "][", "]]]]]}}}}))))"]))
