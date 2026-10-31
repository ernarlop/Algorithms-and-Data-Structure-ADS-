# binary exponentiation: a^n mod m in O(log n)
def binpow(a, n, m):
    result = 1 % m
    a %= m
    while n > 0:
        if n % 2 == 1:  # n is odd: take one a
            result = result * a % m
        a = a * a % m   # square the base
        n //= 2
    return result


a, n, m = map(int, input().split())
print(binpow(a, n, m))
