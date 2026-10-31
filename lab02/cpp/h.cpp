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

int main() {
    int n;
    cin >> n;
    Node* head = read_list(n);

    // Kadane: cur = best sum of a run that ends at this day
    int best = head->data, cur = 0;
    for (Node* p = head; p != NULL; p = p->next) {
        cur = max(p->data, cur + p->data);
        best = max(best, cur);
    }
    cout << best;
}
