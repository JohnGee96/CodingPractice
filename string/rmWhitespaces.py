# Given a null terminated string, remove any white spaces (tabs or spaces).
import re

regex = re.compile(r'[\S]+')

def rm_whitespaces_regex(s):
    return "".join(regex.findall(s))

def rm_whitespace_new(s):
    s = s.replace(" ", "")
    s = s.replace("\t", "")
    s = s.replace("\n", "")
    return s

def rm_whitespace_iter(s):
    l = len(s)
    s = list(s)
    
    # for i in range(l):
    #     if s[i] == ' ' or s[i] == '\t':
    #         s[i] = ''

    read_ptr, write_ptr = 0, 0
    while read_ptr < l and s[read_ptr] != '\0' :
        if s[read_ptr] != ' ' and s[read_ptr] != '\t':
            print("SWAP")
            s[write_ptr] = s[read_ptr]
            write_ptr += 1
            print("".join(s))
        read_ptr += 1
        
    s = s[:write_ptr] # Chop off any remaining string equivalent to ""s[write_ptr] = '\0'"" in C++

    return "".join(s)

print(rm_whitespaces_regex("   spaces\ttab\n \t newline"))
print(rm_whitespace_new("   spaces\ttab\n \t newline"))
print(rm_whitespace_iter("   spaces\ttab \t  "))