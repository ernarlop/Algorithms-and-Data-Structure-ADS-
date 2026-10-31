#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, string> origin; // current nickname -> original nickname
    for (int i = 0; i < n; i++) {
        string oldNick, newNick;
        cin >> oldNick >> newNick;
        string original = oldNick;
        if (origin.count(oldNick)) { // oldNick was already a renamed nickname
            original = origin[oldNick];
            origin.erase(oldNick);
        }
        origin[newNick] = original;
    }

    // flip it: original -> current (map keeps the keys sorted)
    map<string, string> ans;
    for (auto p : origin) ans[p.second] = p.first;

    cout << ans.size() << endl;
    for (auto p : ans) cout << p.first << " " << p.second << endl;
}
