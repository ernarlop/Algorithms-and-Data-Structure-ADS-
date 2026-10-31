#include <bits/stdc++.h>
using namespace std;

vector<int> a;
long long inv = 0; // up to ~5*10^9, does not fit in int

// usual merge sort of a[l..r] + counting inversions while merging
void merge_sort(int l, int r) {
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);

    vector<int> t;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) {
            t.push_back(a[i++]);
        } else {
            inv += m - i + 1; // a[j] is smaller than every element left in a[i..m]
            t.push_back(a[j++]);
        }
    }
    while (i <= m) t.push_back(a[i++]);
    while (j <= r) t.push_back(a[j++]);

    for (int k = 0; k < (int)t.size(); k++) a[l + k] = t[k];
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n - 1);
    cout << inv;
}
