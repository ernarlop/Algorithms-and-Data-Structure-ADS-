class Node:
    def __init__(self, data):
        self.data = data
        self.next = None


n = int(input())
values = list(map(int, input().split()))
x = int(input())

# build the list: every new number goes to the end (tail)
head = tail = None
for v in values:
    node = Node(v)
    if head is None:
        head = node
    else:
        tail.next = node
    tail = node

# 1) delete x from the beginning of the list
while head is not None and head.data == x:
    head = head.next

# 2) delete x from the middle and the end: always look at the NEXT node
cur = head
while cur is not None and cur.next is not None:
    if cur.next.data == x:
        cur.next = cur.next.next  # jump over the deleted node
    else:
        cur = cur.next

res = []
p = head
while p is not None:
    res.append(p.data)
    p = p.next
print(*res)
