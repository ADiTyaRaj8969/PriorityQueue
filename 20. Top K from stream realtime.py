"""
Task: Find top K largest numbers from a stream (real-time input)
Time Complexity: O(log K) per element
Space Complexity: O(K)
"""

import heapq

K=3
pq=[]
stream=[4,5,2,10,8,6]
for x in stream:
    heapq.heappush(pq,x)
    if len(pq)>K: heapq.heappop(pq)
    print('Top K so far:', sorted(pq, reverse=True))
