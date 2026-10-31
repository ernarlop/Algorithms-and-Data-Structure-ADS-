#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    // p[i] - p[i-1] = (s[i] - 97) * 2^i, so we can get every letter back
    string s = "";
    long long prev = 0;
    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        s += char((p - prev) / (1LL << i) + 97);
        prev = p;
    }
    cout << s;
}
