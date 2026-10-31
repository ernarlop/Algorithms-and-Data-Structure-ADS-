#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<double> a(n);
    for (auto &v : a) cin >> v;
    double lo = 0, hi = 1e9; // ищем максимальную длину
    for (int it = 0; it < 100; it++) {
        double x = (lo + hi) / 2;
        long long pieces = 0;
        for (auto v : a) pieces += (long long)(v / x);
        if (pieces >= k) lo = x;
        else hi = x;
    }
    printf("%.9f", lo);
}
