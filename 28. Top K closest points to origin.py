"""
Task: Find the top K closest points to origin (2D plane)
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq

def k_closest(pts,k):
    pq=[]
    for x,y in pts:
        d = x*x + y*y
        heapq.heappush(pq, (-d, x, y))
        if len(pq)>k: heapq.heappop(pq)
    return [(x,y) for (_,x,y) in pq]

print(k_closest([(1,3),(-2,2),(5,8),(0,1)],2))
