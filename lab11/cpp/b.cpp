#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    // Prim's algorithm on the full graph: bridge i-j costs d[i] + d[j]
    const long long INF = LLONG_MAX;
    vector<bool> used(n, false);
    vector<long long> best(n, INF); // the cheapest bridge from the built part to island i
    best[0] = 0;
    long long total = 0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || best[i] < best[u])) u = i;
        used[u] = true;
        total += best[u];
        for (int v = 0; v < n; v++)
            if (!used[v] && d[u] + d[v] < best[v]) best[v] = d[u] + d[v];
    }
    cout << total;
}
