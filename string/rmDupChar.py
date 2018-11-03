# Remove duplicate characters from a string.

def remove_duplicates(s):
    c = set({})
    new_s = ""
    for char in s:
        if char not in c:
            new_s += char
            c.add(char)
    return new_s

print(remove_duplicates("Hello World!"))