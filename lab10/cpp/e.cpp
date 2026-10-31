#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<vector<int>> a(n, vector<int>(n)); // adjacency matrix
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> a[i][j];

    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        x--; y--; z--;
        // all three pairs must be allowed
        if (a[x][y] == 1 && a[y][z] == 1 && a[x][z] == 1) cout << "YES\n";
        else cout << "NO\n";
    }
}
