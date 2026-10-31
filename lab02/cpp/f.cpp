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

// read n numbers and link them into a list, returns the head
Node* read_list(int n) {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* node = new Node(x);
        if (head == NULL) head = node;
        else tail->next = node;
        tail = node;
    }
    return head;
}

void print_list(Node* head) {
    for (Node* p = head; p != NULL; p = p->next) {
        if (p != head) cout << " ";
        cout << p->data;
    }
    cout << "\n";
}

int main() {
    int n, m;
    cin >> n;
    Node* a = read_list(n);
    cin >> m;
    Node* b = read_list(m);

    // merge by re-linking: always attach the smaller head to the tail of the result
    Node* dummy = new Node(0); // a fake first node, so the result is never empty
    Node* tail = dummy;
    while (a != NULL && b != NULL) {
        if (a->data <= b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }
        tail = tail->next;
    }
    if (a != NULL) tail->next = a; // the rest of the list that is left
    else tail->next = b;

    print_list(dummy->next);
}
