#include <bits/stdc++.h>
using namespace std;

// type the string using a stack: '#' removes the last typed letter
string type_text(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '#') {
            if (!st.empty()) st.pop();
        } else {
            st.push(c);
        }
    }
    string res = "";
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }
    return res; // the text is reversed, but that is fine for comparing
}

int main() {
    string a, b;
    cin >> a >> b;
    cout << (type_text(a) == type_text(b) ? "Yes" : "No");
}
