#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> indeg, color, parent;
vector<pair<int, int>> cycle; // edges of the found cycle

// 1) DFS finds any cycle (color: 0 = new, 1 = in the current DFS path, 2 = finished)
void dfs(int u) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (!cycle.empty()) return;
        if (color[v] == 0) {
            parent[v] = u;
            dfs(v);
        } else if (color[v] == 1) { // edge back into the current path -> a cycle v -> ... -> u -> v
            cycle.push_back({u, v});
            for (int x = u; x != v; x = parent[x]) cycle.push_back({parent[x], x});
            return;
        }
    }
    color[u] = 2;
}

// Kahn's topological sort that ignores the edge bu -> bv
bool acyclic_without(int bu, int bv) {
    vector<int> deg = indeg;
    deg[bv]--;
    queue<int> q;
    for (int v = 1; v <= n; v++)
        if (deg[v] == 0) q.push(v);
    int done = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        done++;
        for (int v : adj[u]) {
            if (u == bu && v == bv) continue;
            if (--deg[v] == 0) q.push(v);
        }
    }
    return done == n; // every vertex was taken -> no cycle left
}

int main() {
    cin >> n >> m;
    adj.assign(n + 1, {});
    indeg.assign(n + 1, 0);
    color.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        indeg[y]++;
    }

    for (int s = 1; s <= n && cycle.empty(); s++)
        if (color[s] == 0) dfs(s);

    if (cycle.empty()) {
        cout << "YES";
        return 0;
    }
    // 2) the edge we delete must be on this cycle, so try each of them
    for (auto [u, v] : cycle)
        if (acyclic_without(u, v)) {
            cout << "YES";
            return 0;
        }
    cout << "NO";
}
