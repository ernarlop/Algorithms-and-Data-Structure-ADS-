#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    vector<bool> visited(n + 1, false), is_root(n + 1, false);
    vector<int> parent(n + 1, 0), children(n + 1, 0);
    for (int r = 1; r <= n; r++) {
        if (visited[r]) continue;
        // we go from 1 to n, so r is the smallest vertex of its component -> the root
        is_root[r] = true;
        visited[r] = true;
        queue<int> q;
        q.push(r);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u])
                if (!visited[v]) {
                    visited[v] = true;
                    parent[v] = u;
                    children[u]++;
                    q.push(v);
                }
        }
    }

    int count = 0;
    for (int v = 1; v <= n; v++)
        if (is_root[v] || children[v] > children[parent[v]]) count++;
    cout << count;
}
