#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& v : a) cin >> v;
    sort(a.begin(), a.end()); // = in-order обход BST
    cout << (k > n ? -1 : a[k - 1]);
}
