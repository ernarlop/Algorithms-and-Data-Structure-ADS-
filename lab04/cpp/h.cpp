#include <bits/stdc++.h>
using namespace std;
struct Node { int x; Node *l = 0, *r = 0; };
void ins(Node*& t, int x) { if (!t) t = new Node{x}; else if (x < t->x) ins(t->l, x); else ins(t->r, x); }
int s;
void go(Node* t) { if (!t) return; go(t->r); cout << (s += t->x) << " "; go(t->l); } // от большего к меньшему
int main() {
    int n, x; Node* t = 0; cin >> n;
    while (n--) cin >> x, ins(t, x);
    go(t);
}
