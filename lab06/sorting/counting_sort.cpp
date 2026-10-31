#include <bits/stdc++.h>
using namespace std;

// Counting sort, O(n + MAX): works only for small numbers (here 0..1000000)
int cnt[1000001];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++; // how many times x appears
    }

    for (int v = 0; v <= 1000000; v++)
        for (int j = 0; j < cnt[v]; j++)
            cout << v << " ";
}
