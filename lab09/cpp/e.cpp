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

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        long long k;
        cin >> s >> k;
        long long n = s.size();
        long long period = n - prefix_function(s).back(); // each next copy overlaps the previous one
        cout << n + (k - 1) * period << "\n";
    }
}
