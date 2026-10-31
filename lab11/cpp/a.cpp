#include <bits/stdc++.h>
using namespace std;

vector<int> nxt; // nxt[i] = the first i' >= i whose pair (i', i'+1) is not joined yet

int find(int i) {
    while (nxt[i] != i) {
        nxt[i] = nxt[nxt[i]];
        i = nxt[i];
    }
    return i;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<array<long long, 3>> segs(m); // {cost, l, r}
    for (int i = 0; i < m; i++) cin >> segs[i][1] >> segs[i][2] >> segs[i][0];
    sort(segs.begin(), segs.end()); // Kruskal: cheapest segments first

    // a segment [l, r] joins the whole interval, so only neighbours (i, i+1) matter:
    // every pair (i, i+1) is joined by the first (cheapest) segment that covers it
    nxt.resize(n + 2);
    for (int i = 0; i <= n + 1; i++) nxt[i] = i;

    long long total = 0;
    for (auto [c, l, r] : segs) {
        int i = find(l);
        while (i < r) {
            total += c;     // join i and i+1 with cost c
            nxt[i] = i + 1; // this pair is done, jump over it next time
            i = find(i + 1);
        }
    }
    cout << total;
}
