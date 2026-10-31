#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    // like Dijkstra, but the "length" of a path is its biggest step, not the sum
    const long long INF = LLONG_MAX;
    vector<long long> need(n, INF); // need[v] = the smallest age that is enough to reach city v
    vector<bool> used(n, false);
    need[0] = 0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || need[i] < need[u])) u = i;
        if (u == n - 1) break;
        used[u] = true;
        for (int v = 0; v < n; v++)
            if (!used[v]) {
                long long c = max(need[u], llabs(x[u] - x[v]) + llabs(y[u] - y[v]));
                if (c < need[v]) need[v] = c;
            }
    }
    cout << need[n - 1];
}
