"""
Task: Find the frequency of elements and return the top K frequent elements
Time Complexity: O(n log k)
Space Complexity: O(n)
"""

import heapq
from collections import Counter

def top_k_frequent(a,k):
    cnt = Counter(a)
    pq = []
    for val,f in cnt.items():
        heapq.heappush(pq, (f, val))
        if len(pq)>k: heapq.heappop(pq)
    res = [heapq.heappop(pq)[1] for _ in range(len(pq))]
    return res[::-1]

print('Top K:', top_k_frequent([1,1,1,2,2,3],2))
