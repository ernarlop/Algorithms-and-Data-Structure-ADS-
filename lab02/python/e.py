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
mid = n // 2  # number of the node to delete (from 0)

if mid == 0:
    head = head.next  # n = 1: the only node is deleted
else:
    cur = head
    for _ in range(mid - 1):  # stop right before the middle
        cur = cur.next
    cur.next = cur.next.next

print_list(head)
