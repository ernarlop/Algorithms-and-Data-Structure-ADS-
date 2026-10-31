#include <bits/stdc++.h>
using namespace std;

const long long INF = LLONG_MAX / 4;
int n, m;
vector<vector<pair<int, int>>> adj; // adj[u] = {(v, length)}

vector<long long> dijkstra(int src) {
    vector<long long> dist(n + 1, INF);
    dist[src] = 0;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u])
            if (d + w < dist[v]) {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
    }
    return dist;
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    for (int i = 0; i < m; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        adj[v].push_back({u, c});
        adj[u].push_back({v, c});
    }
    int s, a, b, f;
    cin >> s >> a >> b >> f;

    // the roads are two-way, so distances from a and from b are enough
    vector<long long> da = dijkstra(a), db = dijkstra(b);
    long long ans = min(da[s] + da[b] + db[f],  // s -> a -> b -> f
                        db[s] + da[b] + da[f]); // s -> b -> a -> f
    cout << (ans >= INF ? -1 : ans);
}
