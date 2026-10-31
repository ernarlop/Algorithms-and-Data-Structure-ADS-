#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    long long data;
    Node* next;
    Node(long long data) {
        this->data = data;
        this->next = NULL;
    }
};

int main() {
    int n;
    cin >> n;

    // build the list: every new number goes to the end (tail)
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        long long v;
        cin >> v;
        Node* node = new Node(v);
        if (head == NULL) head = node;
        else tail->next = node;
        tail = node;
    }

    long long x;
    cin >> x;

    // 1) delete x from the beginning of the list
    while (head != NULL && head->data == x) {
        Node* del = head;
        head = head->next;
        delete del;
    }

    // 2) delete x from the middle and the end: always look at the NEXT node
    Node* cur = head;
    while (cur != NULL && cur->next != NULL) {
        if (cur->next->data == x) {
            Node* del = cur->next;
            cur->next = del->next; // jump over the deleted node
            delete del;
        } else {
            cur = cur->next;
        }
    }

    // print the list from head to the end
    for (Node* p = head; p != NULL; p = p->next) {
        if (p != head) cout << " ";
        cout << p->data;
    }
}
