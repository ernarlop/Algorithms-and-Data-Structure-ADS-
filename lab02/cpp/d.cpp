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
    int n;
    cin >> n;
    Node* head = read_list(n);

    // turn every next pointer around
    Node* prev = NULL;
    Node* cur = head;
    while (cur != NULL) {
        Node* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    head = prev;

    print_list(head);
}
