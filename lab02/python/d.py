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


n = int(input())
head = build_list(input().split())

# turn every next pointer around
prev = None
cur = head
while cur is not None:
    nxt = cur.next
    cur.next = prev
    prev = cur
    cur = nxt
head = prev

print_list(head)
