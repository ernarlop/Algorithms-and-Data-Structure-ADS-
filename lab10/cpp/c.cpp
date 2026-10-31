#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    int limit = 2 * max(a, b); // going higher than this is never useful

    // BFS over numbers, par[x] = the number we came to x from
    vector<int> par(limit + 1, -1);
    par[a] = a;
    queue<int> q;
    q.push(a);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        if (x == b) break;
        int next[2] = {x * 2, x - 1};
        for (int y : next)
            if (y >= 1 && y <= limit && par[y] == -1) {
                par[y] = x;
                q.push(y);
            }
    }

    // go back from b to a to restore the numbers
    vector<int> path;
    for (int x = b; x != a; x = par[x]) path.push_back(x);
    reverse(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int i = 0; i < (int)path.size(); i++) {
        if (i > 0) cout << " ";
        cout << path[i];
    }
}
