#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<array<int, 3>> edges; // {u, v, w}
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int w;
            cin >> w;
            if (w != 100000) edges.push_back({i, j, w}); // 100000 means "no edge"
        }

    // Bellman-Ford from all vertices at once (every dist starts at 0)
    vector<long long> dist(n, 0);
    vector<int> par(n, -1);
    int x = -1;
    for (int round = 0; round < n; round++) {
        x = -1;
        for (auto [u, v, w] : edges)
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        if (x == -1) break; // nothing changed -> no negative cycle
    }

    if (x == -1) {
        cout << "NO";
        return 0;
    }
    // something still improved on the n-th round -> a negative cycle exists.
    // walk back n times to be sure we are standing on the cycle
    for (int i = 0; i < n; i++) x = par[x];
    vector<int> cycle = {x};
    for (int v = par[x]; v != x; v = par[v]) cycle.push_back(v);
    cycle.push_back(x);
    reverse(cycle.begin(), cycle.end()); // we walked backwards, so turn it around

    cout << "YES\n" << cycle.size() << "\n";
    for (int i = 0; i < (int)cycle.size(); i++) {
        if (i > 0) cout << " ";
        cout << cycle[i] + 1;
    }
}
