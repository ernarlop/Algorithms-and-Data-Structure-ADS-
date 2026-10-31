#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, ops = 0; long long m, x; cin >> n >> m;
    priority_queue<long long, vector<long long>, greater<>> q; // min-куча
    while (n--) cin >> x, q.push(x);
    while (q.size() > 1 && q.top() < m) { // мешаем две самые слабые
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        q.push(a + 2 * b); ops++;
    }
    cout << (q.top() < m ? -1 : ops);
}
