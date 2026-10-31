#include <bits/stdc++.h>
using namespace std;
struct Node { int x; Node *l = 0, *r = 0; };
void ins(Node*& t, int x) { if (!t) t = new Node{x}; else if (x < t->x) ins(t->l, x); else ins(t->r, x); }
long long s[5000]; int k;
void go(Node* t, int d) { if (!t) return; s[d] += t->x; k = max(k, d + 1); go(t->l, d + 1); go(t->r, d + 1); }
int main() {
    int n, x; Node* t = 0; cin >> n;
    while (n--) cin >> x, ins(t, x);
    go(t, 0);
    cout << k << "\n";
    for (int i = 0; i < k; i++) cout << s[i] << " ";
}
