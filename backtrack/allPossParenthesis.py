# Print all parentheses combinations for a given value 
# n such that they are balanced. Here are a few examples.

def print_all_parenthesis(n):
    print_parenthesis_recur(n, n, "")

def print_parenthesis_recur(left, right, output):
    if left == 0:
        for _ in range(right):
            output += "}"
        print(output)
    else:
        print_parenthesis_recur(left - 1, right - 1, output + "{}")
        if left > 1:
            print_parenthesis_recur(left - 1 , right, output + "{")

    return

print_all_parenthesis(4)