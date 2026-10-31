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

string lower(string s) {
    for (char& c : s) c = tolower(c);
    return s;
}

int main() {
    string p;
    int n;
    cin >> p >> n;
    p = lower(p);
    vector<string> names(n);
    vector<int> overlap(n);
    for (int i = 0; i < n; i++) {
        cin >> names[i];
        // the longest prefix of the name that is also a suffix of p
        overlap[i] = prefix_function(lower(names[i]) + "#" + p).back();
    }

    int best = *max_element(overlap.begin(), overlap.end());
    vector<string> good;
    for (int i = 0; i < n; i++)
        if (overlap[i] == best) good.push_back(names[i]);
    cout << good.size() << "\n";
    for (string& s : good) cout << s << "\n";
}
