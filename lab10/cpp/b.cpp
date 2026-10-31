#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> g[i][j];
    int s, f;
    cin >> s >> f;
    s--; f--;

    // BFS on the adjacency matrix
    vector<int> dist(n, -1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
            if (g[u][v] == 1 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    cout << dist[f];
}
