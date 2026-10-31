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
    int mid = n / 2; // number of the node to delete (from 0)

    if (mid == 0) {
        head = head->next; // n = 1: the only node is deleted
    } else {
        Node* cur = head;
        for (int i = 0; i < mid - 1; i++) cur = cur->next; // stop right before the middle
        cur->next = cur->next->next;
    }

    print_list(head);
}
