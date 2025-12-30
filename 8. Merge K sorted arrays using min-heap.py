"""
Task: Merge K sorted arrays using a min-heap
Time Complexity: O(N log k)
Space Complexity: O(k)
"""

import heapq

lists = [[1,4,7],[2,5,8],[3,6,9]]
pq = []
for i,l in enumerate(lists):
    if l: heapq.heappush(pq, (l[0], i, 0))

out=[]
while pq:
    val, ai, idx = heapq.heappop(pq)
    out.append(val)
    if idx+1 < len(lists[ai]):
        heapq.heappush(pq, (lists[ai][idx+1], ai, idx+1))

print('Merged:', out)
