#include <bits/stdc++.h>
using namespace std;

// two hashes with two different moduli: a collision in both at once is practically impossible
const long long M1 = 1000000007, M2 = 998244353, BASE = 131;
vector<long long> h1, h2, p1, p2;

// h[i] = hash of the first i characters, p[i] = BASE^i
void build(const string& s) {
    int n = s.size();
    h1.assign(n + 1, 0); h2.assign(n + 1, 0);
    p1.assign(n + 1, 1); p2.assign(n + 1, 1);
    for (int i = 0; i < n; i++) {
        h1[i + 1] = (h1[i] * BASE + s[i]) % M1;
        h2[i + 1] = (h2[i] * BASE + s[i]) % M2;
        p1[i + 1] = p1[i] * BASE % M1;
        p2[i + 1] = p2[i] * BASE % M2;
    }
}

// hash of s[l..r) = h[r] - h[l] * BASE^(r-l); both hashes are packed into one number
long long get(int l, int r) {
    long long a = ((h1[r] - h1[l] * p1[r - l]) % M1 + M1) % M1;
    long long b = ((h2[r] - h2[l] * p2[r - l]) % M2 + M2) % M2;
    return a * M2 + b;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<string> patterns(n);
        for (int i = 0; i < n; i++) cin >> patterns[i];
        string text;
        cin >> text;

        // hash of every pattern
        vector<long long> ph(n);
        for (int i = 0; i < n; i++) {
            build(patterns[i]);
            ph[i] = get(0, patterns[i].size());
        }

        // Rabin-Karp: compare the pattern hash with the hash of every window of the text
        build(text);
        vector<int> freq(n, 0);
        for (int k = 0; k < n; k++) {
            int L = patterns[k].size();
            for (int i = 0; i + L <= (int)text.size(); i++)
                if (get(i, i + L) == ph[k]) freq[k]++;
        }

        int best = *max_element(freq.begin(), freq.end());
        cout << best << "\n";
        for (int k = 0; k < n; k++)
            if (freq[k] == best) cout << patterns[k] << "\n";
    }
}
