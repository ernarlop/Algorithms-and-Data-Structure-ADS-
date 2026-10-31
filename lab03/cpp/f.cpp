#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, h;
    cin >> n >> h;
    vector<long long> a(n);
    for (auto &v : a) cin >> v;
    long long lo = 1, hi = 1e9; // ищем минимальное K
    while (lo < hi) {
        long long k = (lo + hi) / 2, hours = 0;
        for (auto v : a) hours += (v + k - 1) / k; // деление с округлением вверх
        if (hours <= h) hi = k;
        else lo = k + 1;
    }
    cout << lo;
}
