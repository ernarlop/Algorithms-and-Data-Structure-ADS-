#include <bits/stdc++.h>
using namespace std;
struct Node { int x; Node *l = 0, *r = 0; };
void ins(Node*& t, int x) { if (!t) t = new Node{x}; else if (x < t->x) ins(t->l, x); else ins(t->r, x); }
void pre(Node* t) { if (!t) return; cout << t->x << " "; pre(t->l); pre(t->r); }
int main() {
    int n, x; Node* t = 0; cin >> n;
    while (n--) cin >> x, ins(t, x);
    cin >> x;
    while (t->x != x) t = x < t->x ? t->l : t->r;
    pre(t);
}
