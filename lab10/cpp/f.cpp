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
    int s, f;
    cin >> s >> f;

    // BFS from s: f is in the same component if BFS reaches it
    vector<bool> visited(n + 1, false);
    visited[s] = true;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
    }
    cout << (visited[f] ? "YES" : "NO");
}
