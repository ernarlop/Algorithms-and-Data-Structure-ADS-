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


n, k = map(int, input().split())
head = build_list(input().split())

# the k-th word becomes the last one, the (k+1)-th becomes the head
kth = head
for _ in range(k - 1):
    kth = kth.next
tail = kth
while tail.next is not None:
    tail = tail.next
new_head = kth.next
kth.next = None
tail.next = head  # the old tail now points to the old head
head = new_head

print_list(head)
