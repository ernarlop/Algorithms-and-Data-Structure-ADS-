#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<char> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    char k;
    cin >> k;

    // the letters are sorted, so the first letter bigger than k is the answer
    for (int i = 0; i < n; i++) {
        if (a[i] > k) {
            cout << a[i];
            return 0;
        }
    }
    cout << a[0]; // nothing is bigger -> wrap around to the first letter
}
