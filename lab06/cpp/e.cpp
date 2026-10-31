#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];

    for (int j = 0; j < m; j++) {
        // copy column j, sort it from big to small, put it back
        vector<int> col(n);
        for (int i = 0; i < n; i++) col[i] = a[i][j];
        sort(col.begin(), col.end(), greater<int>());
        for (int i = 0; i < n; i++) a[i][j] = col[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cout << a[i][j] << " ";
        cout << endl;
    }
}
