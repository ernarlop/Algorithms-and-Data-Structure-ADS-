#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x; cin >> n;
    priority_queue<long long, vector<long long>, greater<>> q; // min-куча
    while (n--) cin >> x, q.push(x);
    long long ans = 0;
    while (q.size() > 1) { // сливаем два самых коротких
        long long a = q.top(); q.pop();
        long long b = q.top(); q.pop();
        ans += a + b; q.push(a + b);
    }
    cout << ans;
}
