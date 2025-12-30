"""
Task: Merge K sorted linked lists using a min-heap
Time Complexity: O(N log k)
Space Complexity: O(k + N)
"""

import heapq


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


# Build three example sorted lists
l1 = Node(1)
l1.next = Node(4)
l1.next.next = Node(7)

l2 = Node(2)
l2.next = Node(5)
l2.next.next = Node(8)

l3 = Node(3)
l3.next = Node(6)
l3.next.next = Node(9)

lists = [l1, l2, l3]

pq = []
counter = 0
for head in lists:
    if head:
        heapq.heappush(pq, (head.val, counter, head))
        counter += 1

dummy = Node(0)
tail = dummy
while pq:
    val, _, node = heapq.heappop(pq)
    tail.next = Node(node.val)
    tail = tail.next
    if node.next:
        heapq.heappush(pq, (node.next.val, counter, node.next))
        counter += 1

res = []
it = dummy.next
while it:
    res.append(it.val)
    it = it.next

print('Merged list:', res)
