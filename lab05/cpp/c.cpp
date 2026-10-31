#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, x, a; cin >> n >> x;
    priority_queue<int> q; // max-куча
    while (n--) cin >> a, q.push(a);
    long long ans = 0;
    while (x--) { // каждому — билет в самый свободный ряд
        int k = q.top(); q.pop();
        ans += k;
        if (k > 1) q.push(k - 1);
    }
    cout << ans;
}
