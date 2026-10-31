#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    // Prim's algorithm: a[i][j] = 0 means the edge already exists (it is free)
    const int INF = INT_MAX;
    vector<bool> used(n, false);
    vector<int> best(n, INF);
    best[0] = 0;
    int total = 0;
    for (int step = 0; step < n; step++) {
        int u = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && (u == -1 || best[i] < best[u])) u = i;
        used[u] = true;
        total += best[u];
        for (int v = 0; v < n; v++)
            if (!used[v] && a[u][v] < best[v]) best[v] = a[u][v];
    }
    cout << total;
}
