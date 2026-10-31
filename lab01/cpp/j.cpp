#include <bits/stdc++.h>
using namespace std;

int main() {
    queue<int> boris, nursik;
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        boris.push(x);
    }
    for (int i = 0; i < 5; i++) {
        int x;
        cin >> x;
        nursik.push(x);
    }

    int moves = 0;
    while (!boris.empty() && !nursik.empty()) {
        int b = boris.front(); boris.pop();
        int n = nursik.front(); nursik.pop();
        moves++;

        bool boris_wins;
        if (b == 0 && n == 9) boris_wins = true;       // 0 beats 9
        else if (b == 9 && n == 0) boris_wins = false;
        else boris_wins = b > n;

        if (boris_wins) {
            boris.push(b);
            boris.push(n);
        } else {
            nursik.push(b);
            nursik.push(n);
        }
    }

    if (nursik.empty()) cout << "Boris " << moves;
    else cout << "Nursik " << moves;
}
