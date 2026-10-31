#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node(string data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        string w;
        cin >> w;
        Node* node = new Node(w);
        if (head == NULL) head = node;
        else tail->next = node;
        tail = node;
    }

    // the k-th word becomes the last one, the (k+1)-th becomes the head
    Node* kth = head;
    for (int i = 1; i < k; i++) kth = kth->next;
    Node* new_head = kth->next;
    kth->next = NULL;
    tail->next = head; // the old tail now points to the old head
    head = new_head;

    for (Node* p = head; p != NULL; p = p->next) {
        if (p != head) cout << " ";
        cout << p->data;
    }
}
