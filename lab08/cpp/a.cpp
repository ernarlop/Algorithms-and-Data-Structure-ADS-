#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

// h = sum of (s[i] - 47) * 11^i, everything modulo 1e9+7
long long digit_hash(string s) {
    long long h = 0, power = 1;
    for (char c : s) {
        h = (h + (c - 47) * power) % MOD;
        power = power * 11 % MOD;
    }
    return h;
}

int main() {
    int n;
    cin >> n;
    vector<string> lines(2 * n);
    set<string> present;
    for (int i = 0; i < 2 * n; i++) {
        cin >> lines[i];
        present.insert(lines[i]);
    }

    int found = 0;
    for (int i = 0; i < 2 * n && found < n; i++) {
        string h = to_string(digit_hash(lines[i]));
        if (present.count(h)) { // its hash is also in the input -> it is a string, not a hash
            cout << "Hash of string \"" << lines[i] << "\" is " << h << "\n";
            found++;
        }
    }
}
