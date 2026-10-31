#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    // 1) find the smallest difference between two neighbours
    int best = INT_MAX;
    for (int i = 1; i < n; i++)
        best = min(best, a[i] - a[i - 1]);

    // 2) print every neighbour pair with that difference
    for (int i = 1; i < n; i++)
        if (a[i] - a[i - 1] == best)
            cout << a[i - 1] << " " << a[i] << " ";
}
