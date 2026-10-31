n = int(input())

# Sieve of Eratosthenes: the 1000-th prime is 7919, so 8000 is enough
limit = 8000
is_prime = [True] * (limit + 1)
is_prime[0] = is_prime[1] = False
i = 2
while i * i <= limit:
    if is_prime[i]:
        for j in range(i * i, limit + 1, i):
            is_prime[j] = False
    i += 1

primes = [i for i in range(2, limit + 1) if is_prime[i]]
print(primes[n - 1])
