"""
Task: Implement a Min Priority Queue class with insertion and deletion
Time Complexity: O(log n) per op
Space Complexity: O(n)
"""

import heapq

class MinPQ:
    def __init__(self): self._a = []
    def push(self,x): heapq.heappush(self._a, x)
    def pop(self): return heapq.heappop(self._a)
    def top(self): return self._a[0]
    def empty(self): return not self._a

if __name__=='__main__':
    pq = MinPQ(); pq.push(4); pq.push(2); pq.push(9)
    print('Top(min):', pq.top()); pq.pop(); print('Top after pop:', pq.top())
