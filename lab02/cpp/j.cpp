#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

Node* insert(Node* head, int x, int p) {
    Node* node = new Node(x);
    if (p == 0) {
        node->next = head;
        return node;
    }
    Node* cur = head;
    for (int i = 0; i < p - 1; i++) cur = cur->next; // the node before position p
    node->next = cur->next;
    cur->next = node;
    return head;
}

Node* remove(Node* head, int p) {
    if (p == 0) return head->next;
    Node* cur = head;
    for (int i = 0; i < p - 1; i++) cur = cur->next;
    cur->next = cur->next->next;
    return head;
}

void print(Node* head) {
    if (head == NULL) {
        cout << -1 << "\n";
        return;
    }
    for (Node* p = head; p != NULL; p = p->next) {
        if (p != head) cout << " ";
        cout << p->data;
    }
    cout << "\n";
}

Node* replace(Node* head, int p1, int p2) {
    Node* cur = head;
    for (int i = 0; i < p1; i++) cur = cur->next;
    int x = cur->data;
    head = remove(head, p1);   // take the node out...
    return insert(head, x, p2); // ...and put it to position p2
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    while (head != NULL) {
        Node* nxt = head->next;
        head->next = prev;
        prev = head;
        head = nxt;
    }
    return prev;
}

int length(Node* head) {
    int len = 0;
    for (Node* p = head; p != NULL; p = p->next) len++;
    return len;
}

Node* cyclic_left(Node* head, int x) {
    if (x == 0) return head;
    // the x-th node becomes the last one, the (x+1)-th becomes the head
    Node* kth = head;
    for (int i = 1; i < x; i++) kth = kth->next;
    Node* tail = kth;
    while (tail->next != NULL) tail = tail->next;
    Node* new_head = kth->next;
    kth->next = NULL;
    tail->next = head;
    return new_head;
}

Node* cyclic_right(Node* head, int x) {
    if (x == 0) return head;
    return cyclic_left(head, length(head) - x); // right by x = left by (len - x)
}

int main() {
    Node* head = NULL;
    int cmd;
    while (cin >> cmd) {
        if (cmd == 0) {
            break;
        } else if (cmd == 1) {
            int x, p;
            cin >> x >> p;
            head = insert(head, x, p);
        } else if (cmd == 2) {
            int p;
            cin >> p;
            head = remove(head, p);
        } else if (cmd == 3) {
            print(head);
        } else if (cmd == 4) {
            int p1, p2;
            cin >> p1 >> p2;
            head = replace(head, p1, p2);
        } else if (cmd == 5) {
            head = reverse(head);
        } else if (cmd == 6) {
            int x;
            cin >> x;
            head = cyclic_left(head, x);
        } else if (cmd == 7) {
            int x;
            cin >> x;
            head = cyclic_right(head, x);
        }
    }
}
