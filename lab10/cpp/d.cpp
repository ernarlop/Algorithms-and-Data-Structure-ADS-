#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    const int INF = INT_MAX;
    vector<int> dist(n + 1, INF); // dist[v] = distance from v to the nearest red vertex

    while (q--) {
        int t, v;
        cin >> t >> v;
        if (t == 1) {
            if (dist[v] == 0) continue;
            // BFS from the new red vertex, but only where it makes the distance smaller
            dist[v] = 0;
            queue<int> bq;
            bq.push(v);
            while (!bq.empty()) {
                int u = bq.front();
                bq.pop();
                for (int w : adj[u])
                    if (dist[u] + 1 < dist[w]) {
                        dist[w] = dist[u] + 1;
                        bq.push(w);
                    }
            }
        } else {
            cout << (dist[v] == INF ? -1 : dist[v]) << "\n";
        }
    }
}
