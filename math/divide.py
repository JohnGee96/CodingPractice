# Integer Division
# Divide two integers without using '/' (division) or '*' (multiplication) operators.

def integer_divide(x, y):
    if y == 0:
        print("ERROR: Divide by zero")
        return -1
    if y == x:
        return 1
    elif x < y:
        return 0
    
    quotient = 1
    divisor = y

    # Finds how many times divisor is in dividend
    while divisor < x:
        divisor <<= 1
        # we can also use 'val = val + val;'
        quotient <<= 1
        # we can also use 'q = q + q;'

    if divisor > x:
        divisor >>= 1
        quotient >>= 1
        print("recur on", x - divisor, y)
        return quotient + integer_divide(x - divisor, y)
    
    return quotient

print(integer_divide(15, 3))