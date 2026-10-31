#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];
    vector<vector<bool>> seen(n, vector<bool>(m, false));

    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
    int islands = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '1' || seen[i][j]) continue;
            // a new island: BFS marks all of its land cells
            islands++;
            seen[i][j] = true;
            queue<pair<int, int>> q;
            q.push({i, j});
            while (!q.empty()) {
                auto [a, b] = q.front();
                q.pop();
                for (int d = 0; d < 4; d++) {
                    int x = a + dx[d], y = b + dy[d];
                    if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] == '1' && !seen[x][y]) {
                        seen[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
    cout << islands;
}
