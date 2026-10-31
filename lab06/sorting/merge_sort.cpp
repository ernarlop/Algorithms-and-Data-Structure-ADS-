#include <bits/stdc++.h>
using namespace std;

// Merge sort, always O(n log n): split in half, sort both halves, merge them
vector<int> a;

void merge_sort(int l, int r) { // sorts a[l..r]
    if (l >= r) return;
    int m = (l + r) / 2;
    merge_sort(l, m);
    merge_sort(m + 1, r);

    // merge the sorted halves a[l..m] and a[m+1..r]
    vector<int> t;
    int i = l, j = m + 1;
    while (i <= m && j <= r) {
        if (a[i] <= a[j]) t.push_back(a[i++]);
        else t.push_back(a[j++]);
    }
    while (i <= m) t.push_back(a[i++]); // leftovers of the left half
    while (j <= r) t.push_back(a[j++]); // leftovers of the right half

    for (int k = 0; k < (int)t.size(); k++) a[l + k] = t[k];
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    merge_sort(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
