#include <bits/stdc++.h>
using namespace std;

// binary exponentiation: a^n mod m in O(log n)
long long binpow(long long a, long long n, long long m) {
    long long result = 1 % m;
    a %= m;
    while (n > 0) {
        if (n % 2 == 1) result = result * a % m; // n is odd: take one a
        a = a * a % m;                           // square the base
        n /= 2;
    }
    return result;
}

int main() {
    long long a, n, m;
    cin >> a >> n >> m;
    cout << binpow(a, n, m);
}
