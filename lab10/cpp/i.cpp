#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indeg(n + 1, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indeg[b]++;
    }

    // topological sort (Kahn): always take a quest with no unfinished requirements,
    // the min-heap gives the smallest such quest first
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int v = 1; v <= n; v++)
        if (indeg[v] == 0) pq.push(v);
    vector<int> order;
    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indeg[v] == 0) pq.push(v);
    }

    if ((int)order.size() == n) {
        cout << "Possible\n";
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << " ";
            cout << order[i];
        }
    } else { // some quests are stuck in a cycle
        cout << "Impossible";
    }
}
