#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    for (auto &v : a) cin >> v;
    // два указателя: окно [l, r], все числа неотрицательные
    long long sum = 0;
    int ans = n, l = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (l <= r && sum >= k) {
            ans = min(ans, r - l + 1);
            sum -= a[l++];
        }
    }
    cout << ans;
}
