"""
Task: Find the kth smallest element in an array
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq

def kth_smallest(a,k):
    # use max-heap via negation
    pq=[]
    for x in a:
        heapq.heappush(pq, -x)
        if len(pq)>k: heapq.heappop(pq)
    return -pq[0]

print('3rd smallest:', kth_smallest([7,10,4,3,20,15],3))
