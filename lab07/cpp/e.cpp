#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    deque<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    // the biggest square is always at one of the two ends of the array,
    // so take it from the front or the back and fill the answer from the end
    vector<int> res(n);
    for (int k = n - 1; k >= 0; k--) {
        if (abs(d.front()) > abs(d.back())) {
            res[k] = d.front() * d.front();
            d.pop_front();
        } else {
            res[k] = d.back() * d.back();
            d.pop_back();
        }
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) cout << " ";
        cout << res[i];
    }
}
