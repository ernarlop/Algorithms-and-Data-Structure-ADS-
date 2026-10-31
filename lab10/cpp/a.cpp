#include <bits/stdc++.h>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> g(m, vector<int>(n));
    vector<vector<int>> t(m, vector<int>(n, 0)); // minute when the cell got its Mario
    queue<pair<int, int>> q;
    int mushrooms = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cin >> g[i][j];
            if (g[i][j] == 2) q.push({i, j});
            else if (g[i][j] == 1) mushrooms++;
        }

    // BFS from all Marios at once: one BFS level = one minute
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int time = 0;
    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        time = t[i][j];
        for (int d = 0; d < 4; d++) {
            int x = i + dx[d], y = j + dy[d];
            if (x >= 0 && x < m && y >= 0 && y < n && g[x][y] == 1) {
                g[x][y] = 2; // the mushroom becomes a Mario
                t[x][y] = t[i][j] + 1;
                mushrooms--;
                q.push({x, y});
            }
        }
    }
    cout << (mushrooms == 0 ? time : -1);
}
