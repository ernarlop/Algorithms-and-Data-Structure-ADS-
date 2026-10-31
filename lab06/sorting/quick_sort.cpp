#include <bits/stdc++.h>
using namespace std;

// Quick sort, O(n log n) on average:
// take the middle element p, move smaller ones left and bigger ones right, repeat on both parts
vector<int> a;

void quick_sort(int l, int r) {
    int p = a[(l + r) / 2];
    int i = l, j = r;
    while (i <= j) {
        while (a[i] < p) i++;
        while (a[j] > p) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quick_sort(l, j);
    if (i < r) quick_sort(i, r);
}

int main() {
    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n > 0) quick_sort(0, n - 1);
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
