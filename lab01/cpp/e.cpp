#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // divide by i while we can; it is enough to try i up to sqrt(n)
    for (long long i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            cout << i << " ";
            n /= i;
        }
    }
    if (n > 1) cout << n; // what is left is a prime factor too
}
