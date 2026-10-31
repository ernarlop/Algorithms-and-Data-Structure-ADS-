#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        // copies always stand next to each other, so compare with the last kept name
        if (names.empty() || names.back() != s) names.push_back(s);
    }

    cout << names.size() << "\n";
    for (int i = 0; i < (int)names.size(); i++) cout << names[i] << "\n";
}
