#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    // like brackets: a letter equal to the top of the stack closes it
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() == c) st.pop();
        else st.push(c);
    }
    cout << (st.empty() ? "YES" : "NO");
}
