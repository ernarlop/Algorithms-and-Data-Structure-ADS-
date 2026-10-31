#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int cnt[26] = {0};
        queue<char> q; // letters that may still be unique, in the order they came

        for (int i = 0; i < n; i++) {
            char c;
            cin >> c;
            cnt[c - 'a']++;
            q.push(c);
            // letters at the front that repeated are never the answer again
            while (!q.empty() && cnt[q.front() - 'a'] > 1) q.pop();

            if (i > 0) cout << " ";
            if (q.empty()) cout << -1;
            else cout << q.front();
        }
        cout << "\n";
    }
}
