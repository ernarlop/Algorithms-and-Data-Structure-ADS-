#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

// DSU: the leader of the set that contains x (with path compression)
int find(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}

// join the sets of a and b; false if they were already together
bool unite(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    parent[a] = b;
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        adj[v].push_back(u);
        adj[u].push_back(v);
    }
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    // go backwards: instead of deleting 1, 2, ..., n we add n, n-1, ..., 1 and use DSU
    vector<int> ans(n + 1); // ans[i] = number of components after deleting vertices 1..i
    int comps = 0;
    for (int v = n; v >= 1; v--) {
        ans[v] = comps; // vertices v+1..n are in the graph right now
        comps++;        // add v as a new component
        for (int u : adj[v])
            if (u > v && unite(u, v)) comps--; // two components became one
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << "\n";
}
