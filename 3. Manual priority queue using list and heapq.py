"""
Task: Implement a priority queue manually using a list and heapq (wrapper)
Time Complexity: O(log n) per push/pop
Space Complexity: O(n)
"""

import heapq

class MinPQ:
    def __init__(self):
        self._a = []
    def push(self,x):
        heapq.heappush(self._a,x)
    def pop(self):
        return heapq.heappop(self._a)
    def top(self):
        return self._a[0]
    def empty(self):
        return not self._a

if __name__ == '__main__':
    pq = MinPQ()
    for v in [5,2,9,1,6]: pq.push(v)
    out = []
    while not pq.empty(): out.append(pq.pop())
    print('MinPQ order:', out)
