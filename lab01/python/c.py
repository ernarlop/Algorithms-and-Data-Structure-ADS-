# a number is prime if it has no divisor from 2 to sqrt(a)
def is_prime(a):
    if a < 2:
        return False
    i = 2
    while i * i <= a:
        if a % i == 0:
            return False
        i += 1
    return True


a = int(input())
print("YES" if is_prime(a) else "NO")
