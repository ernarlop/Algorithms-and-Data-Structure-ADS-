#include <bits/stdc++.h>
using namespace std;
struct Node { int x; Node *l = 0, *r = 0; };
void ins(Node*& t, int x, int d = 0) {
    if (d > 100) return; // глубже 100 не нужно
    if (!t) t = new Node{x};
    else if (x <= t->x) ins(t->l, x, d + 1);
    else ins(t->r, x, d + 1);
}
int main() {
    int n, m, x; string s; Node* t = 0;
    cin >> n >> m;
    while (n--) cin >> x, ins(t, x);
    while (m--) {
        cin >> s;
        Node* p = t;
        for (char c : s) if (p) p = c == 'L' ? p->l : p->r;
        cout << (p ? "YES\n" : "NO\n");
    }
}
