#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int &v : a) cin >> v;
    sort(a.begin(), a.end());
    vector<long long> s(n + 1, 0); // s[i] — сумма первых i сил
    for (int i = 0; i < n; i++) s[i + 1] = s[i] + a[i];
    cin >> q;
    while (q--) {
        int p;
        cin >> p;
        int k = upper_bound(a.begin(), a.end(), p) - a.begin(); // сколько сил <= p
        cout << k << " " << s[k] << "\n";
    }
}
