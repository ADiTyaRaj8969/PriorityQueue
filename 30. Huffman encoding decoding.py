"""
Task: Implement Huffman Encoding and Decoding using Min-Heap
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

import heapq
from collections import Counter

class Node:
    def __init__(self, ch, freq):
        self.ch = ch
        self.freq = freq
        self.left = None
        self.right = None
    def __lt__(self, other):
        return self.freq < other.freq

s = 'aaabbc'
cnt = Counter(s)
pq = [Node(ch,f) for ch,f in cnt.items()]
heapq.heapify(pq)
while len(pq) > 1:
    a = heapq.heappop(pq)
    b = heapq.heappop(pq)
    r = Node(None, a.freq + b.freq)
    r.left = a; r.right = b
    heapq.heappush(pq, r)
root = pq[0]

codes = {}
def build_codes(node, prefix=''):
    if not node: return
    if node.ch is not None:
        codes[node.ch] = prefix
    build_codes(node.left, prefix+'0')
    build_codes(node.right, prefix+'1')

build_codes(root)
print('Codes:', codes)
