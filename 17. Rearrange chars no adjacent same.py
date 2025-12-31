"""
Task: Rearrange characters in a string so no two adjacent characters are the same
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq
from collections import Counter

def rearrange(s):
    cnt = Counter(s)
    pq = [(-f, ch) for ch,f in cnt.items()]
    heapq.heapify(pq)
    res = []
    prev = None
    while pq:
        f, ch = heapq.heappop(pq)
        res.append(ch)
        if prev:
            heapq.heappush(pq, prev)
            prev = None
        f += 1
        if f < 0:
            prev = (f, ch)
    res = ''.join(res)
    return res if len(res) == len(s) else ''

print('Rearranged:', rearrange('aaabc'))
