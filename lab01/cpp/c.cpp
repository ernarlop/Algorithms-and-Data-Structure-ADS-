#include <bits/stdc++.h>
using namespace std;

// a number is prime if it has no divisor from 2 to sqrt(a)
bool is_prime(int a) {
    if (a < 2) return false;
    for (int i = 2; i * i <= a; i++)
        if (a % i == 0) return false;
    return true;
}

int main() {
    int a;
    cin >> a;
    cout << (is_prime(a) ? "YES" : "NO");
}
