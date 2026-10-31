#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    long long lo = 0, hi = 0;
    for (auto &v : a) {
        cin >> v;
        lo = max(lo, v); // ответ не меньше самого большого дома
        hi += v;         // и не больше суммы всех
    }
    while (lo < hi) {
        long long x = (lo + hi) / 2, cur = 0;
        int blocks = 1;
        for (auto v : a) { // жадно набиваем блоки, пока сумма <= x
            if (cur + v > x) { blocks++; cur = 0; }
            cur += v;
        }
        if (blocks <= k) hi = x;
        else lo = x + 1;
    }
    cout << lo;
}
