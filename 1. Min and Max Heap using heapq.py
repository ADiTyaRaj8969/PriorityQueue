"""
Task: Create min-heap and max-heap using heapq
Time Complexity: O(n) to build, O(log n) per push/pop
Space Complexity: O(n)
"""

import heapq

arr = [5,1,8,3,7]

# min-heap
minh = arr[:]
heapq.heapify(minh)
print('Min-heap (pop order):', [heapq.heappop(minh) for _ in range(len(minh))])

# max-heap via negation
maxh = [-x for x in arr]
heapq.heapify(maxh)
print('Max-heap (pop order):', [-heapq.heappop(maxh) for _ in range(len(maxh))])
