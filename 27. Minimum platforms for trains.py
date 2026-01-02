"""
Task: Find the minimum number of platforms required for trains (using heap)
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

import heapq

def min_platforms(arr, dep):
    arr_sorted = sorted(arr)
    dep_sorted = sorted(dep)
    i,j=0,0; n=len(arr)
    pq=[]
    ans=0
    while i<n:
        if not pq or arr_sorted[i] <= pq[0]:
            heapq.heappush(pq, dep_sorted[i])
            ans = max(ans, len(pq))
            i+=1
        else:
            heapq.heappop(pq)
    return ans

print('Min platforms example (not exact):', 3)
