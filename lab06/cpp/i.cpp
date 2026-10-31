#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // counting sort: count every letter...
    int cnt[26] = {0};
    for (char c : s) cnt[c - 'a']++;

    // ...then print them from 'a' to 'z'
    string res = "";
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < cnt[i]; j++)
            res += char('a' + i);
    cout << res;
}
