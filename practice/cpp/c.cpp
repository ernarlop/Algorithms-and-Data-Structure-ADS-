#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n + 1); // a[1..n], numbered from 1 like in the statement
    for (int i = 1; i <= n; i++) cin >> a[i];

    // Lomuto partition
    long long pivot = a[n]; // 1) the pivot is the last element
    int i = 0;
    for (int j = 1; j <= n - 1; j++) { // 2) smaller elements go to the front
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[n]); // 3) put the pivot right after the smaller ones

    for (int k = 1; k <= n; k++) {
        if (k > 1) cout << " ";
        cout << a[k];
    }
}
