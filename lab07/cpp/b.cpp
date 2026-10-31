#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x;
    queue<int> a, b;
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> x; a.push(x); }
    cin >> m;
    for (int i = 0; i < m; i++) { cin >> x; b.push(x); }

    // merge: always take the smaller of the two front elements
    vector<int> res;
    while (!a.empty() && !b.empty()) {
        if (a.front() <= b.front()) { res.push_back(a.front()); a.pop(); }
        else { res.push_back(b.front()); b.pop(); }
    }
    // the tail: whatever is left in one of the queues
    while (!a.empty()) { res.push_back(a.front()); a.pop(); }
    while (!b.empty()) { res.push_back(b.front()); b.pop(); }

    for (int i = 0; i < (int)res.size(); i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
}
