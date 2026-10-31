#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        // read the words of one line: after each word look at the next character,
        // if it is the end of the line - this set is finished
        vector<string> w;
        string s;
        while (true) {
            cin >> s;
            w.push_back(s);
            while (cin.peek() == ' ') cin.get(); // skip spaces
            if (cin.peek() == '\n' || cin.peek() == '\r' || cin.peek() == EOF) break;
        }

        // min-heap of (length, position):
        // shorter words come out first; equal length -> the one that was earlier (stable)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (int i = 0; i < (int)w.size(); i++) pq.push({(int)w[i].size(), i});

        bool first = true;
        while (!pq.empty()) {
            if (!first) cout << " ";
            cout << w[pq.top().second];
            pq.pop();
            first = false;
        }
        cout << "\n";
    }
}
