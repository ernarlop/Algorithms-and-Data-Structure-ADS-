#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];
    vector<int> order(n);
    for (int i = 0; i < n; i++) {
        cin >> order[i];
        order[i]--;
    }

    // renumber the vertices: the k-th added vertex gets number k
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) d[i][j] = a[order[i]][order[j]];

    for (int k = 0; k < n; k++) {
        // Floyd-Warshall step: now paths may also go through vertex k
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

        // the longest shortest path among the added vertices 0..k
        int best = 0;
        for (int i = 0; i <= k; i++)
            for (int j = 0; j <= k; j++) best = max(best, d[i][j]);
        cout << best << "\n";
    }
}
