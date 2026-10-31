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

# delete every second node: the node after cur is skipped
cur = head
while cur is not None and cur.next is not None:
    cur.next = cur.next.next
    cur = cur.next

print_list(head)
