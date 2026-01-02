"""
Task: Convert min-heap to max-heap (and vice versa)
Time Complexity: O(n)
Space Complexity: O(1)
"""

import heapq

a=[1,3,5,7,9]
# as min-heap
heapq.heapify(a)
# convert to max-heap by negation
maxh=[-x for x in a]
print('Converted max-heap internal array (negated):', maxh)
