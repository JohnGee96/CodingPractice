# Find the nth fibonacci number.
# Fibonacci numbers are defined as:
# Fib(0): 0
# Fib(1): 1
# Fib(N): Fib(N-1) + Fib(N-2), for N >= 2


# O(n) memory, O(n) complexity
class Fibonacci(object):
    def __init__(self):
        self.dp_table = [0, 1]

    def get_fibonacci(self, n):
        if n < len(self.dp_table):
            return self.dp_table[n]
        fb = self.get_fibonacci(n - 1) + self.get_fibonacci(n - 2)
        self.dp_table.append(fb)
        return fb

# O(1) memory, O(n) complexity
def get_fibonacci(n):
    if n == 0 or n == 1:
        return n
    # fib(n) = fib(n-1) + fib(n-2)
    n_1 = 1 # (n-1)
    n_2 = 0 # (n-2)
    res = 0
    i = 2
    while i <= n:
        res = n_1 + n_2
        n_2 = n_1
        n_1 = res
        i += 1
    return res

f = Fibonacci()
print(f.get_fibonacci(9))