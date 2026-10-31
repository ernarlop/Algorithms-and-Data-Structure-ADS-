import sys


class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def insert(head, x, p):
    node = Node(x)
    if p == 0:
        node.next = head
        return node
    cur = head
    for _ in range(p - 1):  # the node before position p
        cur = cur.next
    node.next = cur.next
    cur.next = node
    return head


def remove(head, p):
    if p == 0:
        return head.next
    cur = head
    for _ in range(p - 1):
        cur = cur.next
    cur.next = cur.next.next
    return head


def print_list(head):
    if head is None:
        out.append("-1")
        return
    vals = []
    p = head
    while p is not None:
        vals.append(str(p.data))
        p = p.next
    out.append(" ".join(vals))


def replace(head, p1, p2):
    cur = head
    for _ in range(p1):
        cur = cur.next
    x = cur.data
    head = remove(head, p1)     # take the node out...
    return insert(head, x, p2)  # ...and put it to position p2


def reverse(head):
    prev = None
    while head is not None:
        nxt = head.next
        head.next = prev
        prev = head
        head = nxt
    return prev


def length(head):
    n = 0
    while head is not None:
        n += 1
        head = head.next
    return n


def cyclic_left(head, x):
    if x == 0:
        return head
    # the x-th node becomes the last one, the (x+1)-th becomes the head
    kth = head
    for _ in range(x - 1):
        kth = kth.next
    tail = kth
    while tail.next is not None:
        tail = tail.next
    new_head = kth.next
    kth.next = None
    tail.next = head
    return new_head


def cyclic_right(head, x):
    if x == 0:
        return head
    return cyclic_left(head, length(head) - x)  # right by x = left by (len - x)


data = sys.stdin.read().split()
pos = 0
head = None
out = []
while pos < len(data):
    cmd = int(data[pos])
    pos += 1
    if cmd == 0:
        break
    elif cmd == 1:
        head = insert(head, int(data[pos]), int(data[pos + 1]))
        pos += 2
    elif cmd == 2:
        head = remove(head, int(data[pos]))
        pos += 1
    elif cmd == 3:
        print_list(head)
    elif cmd == 4:
        head = replace(head, int(data[pos]), int(data[pos + 1]))
        pos += 2
    elif cmd == 5:
        head = reverse(head)
    elif cmd == 6:
        head = cyclic_left(head, int(data[pos]))
        pos += 1
    elif cmd == 7:
        head = cyclic_right(head, int(data[pos]))
        pos += 1
print("\n".join(out))
