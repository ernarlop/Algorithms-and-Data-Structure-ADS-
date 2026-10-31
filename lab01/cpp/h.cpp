#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // the stack keeps candidates for "nearest smaller on the left"
    stack<int> st;
    for (int i = 0; i < n; i++) {
        while (!st.empty() && st.top() >= a[i]) st.pop(); // not smaller -> useless now
        if (st.empty()) cout << -1 << " ";
        else cout << st.top() << " ";
        st.push(a[i]);
    }
}
