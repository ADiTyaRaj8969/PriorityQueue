"""
Task: Insert elements into a priority queue and print in sorted order
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

import heapq

data = [4,1,7,3,9]
minh = []
for x in data:
    heapq.heappush(minh, x)

print('Sorted order (ascending):', [heapq.heappop(minh) for _ in range(len(minh))])
