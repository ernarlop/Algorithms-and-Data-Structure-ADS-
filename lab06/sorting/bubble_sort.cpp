#include <bits/stdc++.h>
using namespace std;

// Bubble sort, O(n^2): swap wrong neighbours, big numbers "bubble up" to the end
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; // no swaps -> already sorted
    }

    for (int i = 0; i < n; i++) cout << a[i] << " ";
}
