#include <bits/stdc++.h>
using namespace std;

// pi[i] = length of the longest proper prefix of s[0..i] that is also its suffix
vector<int> prefix_function(const string& s) {
    int n = s.size();
    vector<int> pi(n, 0);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

// KMP: start positions (from 0) of all occurrences of pattern in text
vector<int> kmp(const string& pattern, const string& text) {
    int m = pattern.size();
    vector<int> pi = prefix_function(pattern + "#" + text);
    vector<int> res;
    for (int i = 0; i < (int)pi.size(); i++)
        if (pi[i] == m) res.push_back(i - 2 * m);
    return res;
}

int main() {
    string a, b;
    cin >> a >> b;
    int k = (b.size() + a.size() - 1) / a.size(); // the fewest copies of a that are at least as long as b

    string text = "";
    for (int i = 0; i < k + 1; i++) text += a; // more than k + 1 copies are never needed
    vector<int> occ = kmp(b, text);

    if (occ.empty()) cout << -1;
    else if (occ[0] + b.size() <= k * a.size()) cout << k; // the first occurrence already fits into k copies
    else cout << k + 1;
}
