n = int(input())

# divide by i while we can; it is enough to try i up to sqrt(n)
factors = []
i = 2
while i * i <= n:
    while n % i == 0:
        factors.append(i)
        n //= i
    i += 1
if n > 1:  # what is left is a prime factor too
    factors.append(n)
print(*factors)
