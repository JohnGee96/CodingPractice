# Your friend is typing his name into a keyboard.  
# Sometimes, when typing a character c, the key might
# get long pressed, and the character will be typed 1 or more times.
# You examine the typed characters of the keyboard. 
# Return True if it is possible that it was your friends name, 
# with some characters (possibly none) being long pressed.

# Example 1:

# Input: name = "alex", typed = "aaleex"
# Output: true
# Explanation: 'a' and 'e' in 'alex' were long pressed.
# Example 2:

# Input: name = "saeed", typed = "ssaaedd"
# Output: false
# Explanation: 'e' must have been pressed twice, but it wasn't in the typed output.
# Example 3:

# Input: name = "leelee", typed = "lleeelee"
# Output: true

def isLongPressedName(name, typed):
    """
    :type name: str
    :type typed: str
    :rtype: bool
    """
    if name == typed:
        return True
    else:
        name_ptr = typed_ptr = 0
        while typed_ptr < len(typed) and name_ptr < len(name):
            # print("LOOP")
            if name[name_ptr] == typed[typed_ptr]:
                typed_ptr += 1
                name_ptr += 1
            else:
                if typed[typed_ptr] == name[name_ptr - 1]:
                    typed_ptr += 1
                else:
                    return False
        if name_ptr == len(name):
            return True
        else:
            return False

print(isLongPressedName("alex","aaleex"))
print(isLongPressedName("saeed", "ssaaedd"))
print(isLongPressedName("leelee","lleeelee"))
print(isLongPressedName("aabbcc","aabbcc"))
print(isLongPressedName("d","ddabc"))