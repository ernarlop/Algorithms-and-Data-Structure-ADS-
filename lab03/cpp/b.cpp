#include <bits/stdc++.h>
using namespace std;

vector<int> a;

// сколько элементов в отрезке [l, r]
int cnt(int l, int r) {
    if (l > r) return 0;
    return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
}

int main() {
    int n, q;
    cin >> n >> q;
    a.resize(n);
    for (int &v : a) cin >> v;
    sort(a.begin(), a.end());
    while (q--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        // |A ∪ B| = |A| + |B| - |A ∩ B|
        cout << cnt(l1, r1) + cnt(l2, r2) - cnt(max(l1, l2), min(r1, r2)) << "\n";
    }
}
