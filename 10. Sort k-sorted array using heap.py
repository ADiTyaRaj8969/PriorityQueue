"""
Task: Sort a nearly sorted (k-sorted) array using a heap
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq

def sort_k_sorted(a,k):
    pq = []
    res = []
    for i,x in enumerate(a):
        heapq.heappush(pq,x)
        if len(pq)>k: res.append(heapq.heappop(pq))
    while pq: res.append(heapq.heappop(pq))
    return res

print('Sorted:', sort_k_sorted([3,2,6,5,4,8],2))
