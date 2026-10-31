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
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    vector<array<int, 3>> edges; // {cost, a, b}
    for (int i = 0; i < m; i++) {
        string kind;
        int a, b, c;
        cin >> kind >> a >> b >> c;
        int price;
        if (kind == "big") price = x;
        else if (kind == "small") price = y;
        else price = min(x, y); // "both": take the cheaper asphalt
        edges.push_back({c * price, a, b});
    }

    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) parent[i] = i;

    // Kruskal: take the cheapest roads that connect new parts
    sort(edges.begin(), edges.end());
    long long total = 0;
    for (auto [w, a, b] : edges)
        if (unite(a, b)) total += w;
    cout << total;
}
