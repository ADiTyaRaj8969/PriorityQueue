"""
Task: Implement a Max Priority Queue class using list (heapq with negation)
Time Complexity: O(log n) per push/pop
Space Complexity: O(n)
"""

import heapq

class MaxPQ:
    def __init__(self): self._a = []
    def push(self,x): heapq.heappush(self._a, -x)
    def pop(self): return -heapq.heappop(self._a)
    def top(self): return -self._a[0]
    def empty(self): return not self._a

if __name__=='__main__':
    pq = MaxPQ(); pq.push(3); pq.push(1); pq.push(5)
    print('Top:', pq.top()); pq.pop(); print('Top after pop:', pq.top())
