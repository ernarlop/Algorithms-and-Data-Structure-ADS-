#include <bits/stdc++.h>
using namespace std;
struct Node { int x; Node *l = 0, *r = 0; };
void ins(Node*& t, int x) { if (!t) t = new Node{x}; else if (x < t->x) ins(t->l, x); else if (x > t->x) ins(t->r, x); }
int ans;
int h(Node* t) {
    if (!t) return 0;
    int a = h(t->l), b = h(t->r);
    ans = max(ans, a + b + 1);
    return max(a, b) + 1;
}
int main() {
    int n, x; Node* t = 0; cin >> n;
    while (n--) cin >> x, ins(t, x);
    h(t);
    cout << ans;
}
