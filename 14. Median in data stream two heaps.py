"""
Task: Find median in a data stream using two heaps
Time Complexity: O(log n) per insertion
Space Complexity: O(n)
"""

import heapq

lowers = [] # max-heap via neg
highers = [] # min-heap

stream = [5,15,1,3]
for x in stream:
    if not lowers or x < -lowers[0]:
        heapq.heappush(lowers, -x)
    else:
        heapq.heappush(highers, x)
    if len(lowers) > len(highers) + 1:
        heapq.heappush(highers, -heapq.heappop(lowers))
    elif len(highers) > len(lowers) + 1:
        heapq.heappush(lowers, -heapq.heappop(highers))
    if len(lowers) == len(highers):
        median = (-lowers[0] + highers[0]) / 2.0
    else:
        median = -lowers[0] if len(lowers) > len(highers) else highers[0]
    print('Median so far:', median)
