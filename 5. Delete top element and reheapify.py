"""
Task: Delete the top element and re-heapify
Time Complexity: O(log n)
Space Complexity: O(1) extra
"""

import heapq

a = [10,4,7,2,9]
heapq.heapify(a)
print('Before pop:', a)
heapq.heappop(a)
print('After pop:', a)
