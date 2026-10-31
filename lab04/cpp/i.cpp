#include <bits/stdc++.h>
using namespace std;
struct Node { int x; Node *l = 0, *r = 0; };
void ins(Node*& t, int x) { if (!t) t = new Node{x}; else if (x < t->x) ins(t->l, x); else ins(t->r, x); }
int lv(Node* t) { if (!t) return 0; if (!t->l && !t->r) return 1; return lv(t->l) + lv(t->r); }
int main() {
    int n, x; Node* t = 0; cin >> n;
    while (n--) cin >> x, ins(t, x);
    cout << lv(t);
}
