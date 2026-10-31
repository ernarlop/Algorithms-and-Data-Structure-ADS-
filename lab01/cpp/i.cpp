#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        // repeat the trick with positions 0..n-1 instead of cards
        queue<int> q;
        for (int i = 0; i < n; i++) q.push(i);
        vector<int> deck(n);
        for (int card = 1; card <= n; card++) {
            int moves = card % q.size(); // moving q.size() cards gives the same deck
            for (int j = 0; j < moves; j++) {
                q.push(q.front());
                q.pop();
            }
            deck[q.front()] = card; // this position must hold card number "card"
            q.pop();
        }

        for (int i = 0; i < n; i++) cout << deck[i] << " ";
        cout << "\n";
    }
}
