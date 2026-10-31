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


n = int(input())
head = build_list(map(int, input().split()))

# Kadane: cur = best sum of a run that ends at this day
best = head.data
cur = 0
p = head
while p is not None:
    cur = max(p.data, cur + p.data)
    best = max(best, cur)
    p = p.next
print(best)
