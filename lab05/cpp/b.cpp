#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x; cin >> n;
    priority_queue<int> q; // max-куча
    while (n--) cin >> x, q.push(x);
    while (q.size() > 1) { // разбиваем два самых тяжёлых
        int y = q.top(); q.pop();
        int x = q.top(); q.pop();
        if (y != x) q.push(y - x);
    }
    cout << (q.empty() ? 0 : q.top());
}
