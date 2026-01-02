"""
Task: Find the kth smallest element in a sorted matrix (rows and cols sorted)
Time Complexity: O(k log n)
Space Complexity: O(n)
"""

import heapq

def kth_smallest_matrix(mat,k):
    n=len(mat)
    pq=[]
    for i in range(n): heapq.heappush(pq, (mat[i][0], i, 0))
    val=None
    while k:
        val,i,j = heapq.heappop(pq)
        if j+1 < len(mat[i]): heapq.heappush(pq, (mat[i][j+1], i, j+1))
        k-=1
    return val

print(kth_smallest_matrix([[1,5,9],[10,11,13],[12,13,15]],8))
