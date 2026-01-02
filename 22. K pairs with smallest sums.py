"""
Task: Find k pairs with smallest sums from two sorted arrays
Time Complexity: O(k log k)
Space Complexity: O(k)
"""

import heapq

def k_smallest_pairs(A,B,k):
    pq=[]
    for i in range(min(len(A),k)): heapq.heappush(pq, (A[i]+B[0], i, 0))
    res=[]
    while k and pq:
        s,i,j=heapq.heappop(pq); res.append((A[i],B[j])); k-=1
        if j+1 < len(B): heapq.heappush(pq, (A[i]+B[j+1], i, j+1))
    return res

print('Pairs:', k_smallest_pairs([1,7,11],[2,4,6],3))
