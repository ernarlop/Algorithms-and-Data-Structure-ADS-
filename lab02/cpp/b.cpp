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

    // delete every second node: the node after cur is skipped
    Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        Node* del = cur->next;
        cur->next = del->next;
        delete del;
        cur = cur->next;
    }

    print_list(head);
}
