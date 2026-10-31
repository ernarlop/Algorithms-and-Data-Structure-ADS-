#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> air(n + 1, vector<bool>(n + 1, false));
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        air[u][v] = air[v][u] = true;
    }

    // the pair (1, n) is either an airline or a road, so one of them gets there in 1 hour;
    // the answer is the shortest time of the other one (they never meet on the way)
    bool use_air = !air[1][n];

    vector<int> dist(n + 1, -1);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
            if (v != u && air[u][v] == use_air && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
    }
    cout << dist[n];
}
