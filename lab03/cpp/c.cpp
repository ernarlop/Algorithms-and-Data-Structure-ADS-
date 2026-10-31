#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n); // p[i] — строка, на которой заканчивается блок i
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i) p[i] += p[i - 1];
    }
    while (m--) {
        int b;
        cin >> b;
        // первый блок, который заканчивается не раньше строки b
        cout << lower_bound(p.begin(), p.end(), b) - p.begin() + 1 << "\n";
    }
}
