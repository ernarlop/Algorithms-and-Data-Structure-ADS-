#include <bits/stdc++.h>
using namespace std;

// "DD-MM-YYYY" -> "YYYYMMDD", then simple string comparison sorts by date
string key(string s) {
    return s.substr(6, 4) + s.substr(3, 2) + s.substr(0, 2);
}

bool cmp(string a, string b) {
    return key(a) < key(b);
}

int main() {
    int n;
    cin >> n;
    vector<string> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    sort(d.begin(), d.end(), cmp);

    for (int i = 0; i < n; i++) cout << d[i] << endl;
}
