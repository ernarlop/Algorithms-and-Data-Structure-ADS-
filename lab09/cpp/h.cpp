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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = prefix_function(s);

    // a + c == b + c  means  a == b, so s = a + a + c
    // s[0..L) == s[L..2L)  exactly when the smallest period of s[0..2L) divides L
    long long count = 0;
    for (int L = 1; 2 * L < n; L++) {
        int period = 2 * L - pi[2 * L - 1];
        if (L % period == 0) count++;
    }
    cout << count;
}
