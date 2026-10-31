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
    string s1, s2, t;
    cin >> s1 >> s2 >> t;
    int m = t.size();

    build(t);
    long long ht = get(0, m);
    build(s1);
    vector<long long> w1(s1.size() + 1);
    for (int i = 0; i + m <= (int)s1.size(); i++) w1[i] = get(i, i + m);
    build(s2);

    // Rabin-Karp: compare hashes of windows instead of whole strings
    int count = 0;
    for (int i = 0; i + m <= (int)s1.size() && i + m <= (int)s2.size(); i++)
        if (w1[i] == ht && get(i, i + m) == ht) count++;
    cout << count;
}
