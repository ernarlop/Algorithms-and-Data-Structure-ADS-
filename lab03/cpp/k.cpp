#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, n, m;
    cin >> t;
    vector<int> q(t);
    for (int &v : q) cin >> v;
    cin >> n >> m;
    map<int, pair<int, int>> pos; // значение -> (строка, столбец)
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            pos[x] = {i, j};
        }
    for (int v : q) {
        if (pos.count(v)) cout << pos[v].first << " " << pos[v].second << "\n";
        else cout << -1 << "\n";
    }
}
