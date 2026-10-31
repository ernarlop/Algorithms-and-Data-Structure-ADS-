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
    string s, t;
    int k;
    cin >> s >> k >> t;
    cout << ((int)kmp(s, t).size() >= k ? "YES" : "NO");
}
