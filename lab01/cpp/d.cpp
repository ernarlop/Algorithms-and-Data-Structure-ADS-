#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Sieve of Eratosthenes: the 1000-th prime is 7919, so 8000 is enough
    int limit = 8000;
    vector<bool> is_prime(limit + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= limit; i++)
        if (is_prime[i])
            for (int j = i * i; j <= limit; j += i)
                is_prime[j] = false;

    vector<int> primes;
    for (int i = 2; i <= limit; i++)
        if (is_prime[i]) primes.push_back(i);

    cout << primes[n - 1];
}
