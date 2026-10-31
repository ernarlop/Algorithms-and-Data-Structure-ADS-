#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x;
    cin >> n;
    vector<int> a(n);
    for (int &v : a) cin >> v;
    cin >> x;
    // binary_search делит отрезок пополам на каждом шаге
    cout << (binary_search(a.begin(), a.end(), x) ? "Yes" : "No");
}
