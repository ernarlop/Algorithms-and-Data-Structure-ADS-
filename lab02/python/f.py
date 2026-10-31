import sys

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


def build_list(values):
    # link the values into a list, returns the head
    head = tail = None
    for x in values:
        node = Node(x)
        if head is None:
            head = node
        else:
            tail.next = node
        tail = node
    return head


def print_list(head):
    out = []
    p = head
    while p is not None:
        out.append(str(p.data))
        p = p.next
    print(" ".join(out))


data = list(map(int, sys.stdin.read().split()))
n = data[0]
a = build_list(data[1:1 + n])
m = data[1 + n]
b = build_list(data[2 + n:2 + n + m])

# merge by re-linking: always attach the smaller head to the tail of the result
dummy = Node(0)  # a fake first node, so the result is never empty
tail = dummy
while a is not None and b is not None:
    if a.data <= b.data:
        tail.next = a
        a = a.next
    else:
        tail.next = b
        b = b.next
    tail = tail.next
tail.next = a if a is not None else b  # the rest of the list that is left

print_list(dummy.next)
