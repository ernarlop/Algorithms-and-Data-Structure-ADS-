#include <bits/stdc++.h>
using namespace std;

typedef pair<int, vector<int>> Row; // (-sum, the row itself)

int main() {
    int n, m;
    cin >> n >> m;

    // min-heap of (-sum, row): the biggest sum comes out first,
    // equal sums -> rows are compared element by element (lexicographically)
    priority_queue<Row, vector<Row>, greater<Row>> pq;
    for (int i = 0; i < n; i++) {
        vector<int> row(m);
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cin >> row[j];
            sum += row[j];
        }
        pq.push({-sum, row});
    }

    while (!pq.empty()) {
        vector<int> row = pq.top().second;
        pq.pop();
        for (int j = 0; j < m; j++) {
            if (j > 0) cout << " ";
            cout << row[j];
        }
        cout << "\n";
    }
}
