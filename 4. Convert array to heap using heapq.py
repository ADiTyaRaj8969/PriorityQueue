"""
Task: Convert an array into a heap (heapq.heapify)
Time Complexity: O(n)
Space Complexity: O(1) extra
"""

import heapq

a = [4,1,7,3,9]
heapq.heapify(a)
print('Heapified array (min-heap internal):', a)
