#include <bits/stdc++.h>
using namespace std;
vector<int> ch[1001]; int cnt[1001];
void go(int v, int d) { cnt[d]++; for (int u : ch[v]) go(u, d + 1); }
int main() {
    int n, x, y, z; cin >> n;
    for (int i = 1; i < n; i++) cin >> x >> y >> z, ch[x].push_back(y);
    go(1, 0);
    cout << *max_element(cnt, cnt + n);
}
