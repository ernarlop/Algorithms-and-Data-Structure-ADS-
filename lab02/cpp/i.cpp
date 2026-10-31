#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string data;
    Node *next, *prev;
    Node(string data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
public:
    Node *front, *back;
    LinkedList() {
        front = NULL;
        back = NULL;
    }

    bool empty() {
        return front == NULL;
    }

    void add_front(string s) {
        Node* node = new Node(s);
        if (front == NULL) {
            front = back = node;
        } else {
            node->next = front;
            front->prev = node;
            front = node;
        }
    }

    void add_back(string s) {
        Node* node = new Node(s);
        if (back == NULL) {
            front = back = node;
        } else {
            node->prev = back;
            back->next = node;
            back = node;
        }
    }

    string erase_front() {
        string s = front->data;
        front = front->next;
        if (front == NULL) back = NULL;
        else front->prev = NULL;
        return s;
    }

    string erase_back() {
        string s = back->data;
        back = back->prev;
        if (back == NULL) front = NULL;
        else back->next = NULL;
        return s;
    }

    void clear() {
        front = back = NULL;
    }
};

int main() {
    LinkedList list;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "add_front") {
            string s;
            cin >> s;
            list.add_front(s);
            cout << "ok\n";
        } else if (cmd == "add_back") {
            string s;
            cin >> s;
            list.add_back(s);
            cout << "ok\n";
        } else if (cmd == "erase_front") {
            if (list.empty()) cout << "error\n";
            else cout << list.erase_front() << "\n";
        } else if (cmd == "erase_back") {
            if (list.empty()) cout << "error\n";
            else cout << list.erase_back() << "\n";
        } else if (cmd == "front") {
            if (list.empty()) cout << "error\n";
            else cout << list.front->data << "\n";
        } else if (cmd == "back") {
            if (list.empty()) cout << "error\n";
            else cout << list.back->data << "\n";
        } else if (cmd == "clear") {
            list.clear();
            cout << "ok\n";
        } else if (cmd == "exit") {
            cout << "goodbye\n";
            break;
        }
    }
}
