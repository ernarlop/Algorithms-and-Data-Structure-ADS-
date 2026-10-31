#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int q;
    cin >> q;
    while (q--) {
        long long x;
        cin >> x;

        // lower bound: the first position where a[pos] >= x
        // the answer is somewhere in [l, r]; r = n means "no such element"
        int l = 0, r = n;
        while (l < r) {
            int m = (l + r) / 2;
            if (a[m] >= x) r = m; // m fits, but maybe there is one more to the left
            else l = m + 1;       // a[m] is too small, the answer is to the right
        }

        if (l == n) cout << -1 << "\n";
        else cout << l + 1 << "\n"; // indices start from 1
    }
}
