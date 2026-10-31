import sys


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None


class LinkedList:
    def __init__(self):
        self.front = None
        self.back = None

    def empty(self):
        return self.front is None

    def add_front(self, s):
        node = Node(s)
        if self.front is None:
            self.front = self.back = node
        else:
            node.next = self.front
            self.front.prev = node
            self.front = node

    def add_back(self, s):
        node = Node(s)
        if self.back is None:
            self.front = self.back = node
        else:
            node.prev = self.back
            self.back.next = node
            self.back = node

    def erase_front(self):
        s = self.front.data
        self.front = self.front.next
        if self.front is None:
            self.back = None
        else:
            self.front.prev = None
        return s

    def erase_back(self):
        s = self.back.data
        self.back = self.back.prev
        if self.back is None:
            self.front = None
        else:
            self.back.next = None
        return s

    def clear(self):
        self.front = self.back = None


lst = LinkedList()
out = []
for line in sys.stdin:
    w = line.split()
    if not w:
        continue
    cmd = w[0]
    if cmd == "add_front":
        lst.add_front(w[1])
        out.append("ok")
    elif cmd == "add_back":
        lst.add_back(w[1])
        out.append("ok")
    elif cmd == "erase_front":
        out.append("error" if lst.empty() else lst.erase_front())
    elif cmd == "erase_back":
        out.append("error" if lst.empty() else lst.erase_back())
    elif cmd == "front":
        out.append("error" if lst.empty() else lst.front.data)
    elif cmd == "back":
        out.append("error" if lst.empty() else lst.back.data)
    elif cmd == "clear":
        lst.clear()
        out.append("ok")
    elif cmd == "exit":
        out.append("goodbye")
        break
print("\n".join(out))
