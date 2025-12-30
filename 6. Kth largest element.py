"""
Task: Find the kth largest element in an array
Time Complexity: O(n log k)
Space Complexity: O(k)
"""

import heapq

def kth_largest(a,k):
    minh=[]
    for x in a:
        heapq.heappush(minh,x)
        if len(minh)>k: heapq.heappop(minh)
    return minh[0]

print('2nd largest:', kth_largest([3,2,1,5,6,4], 2))
