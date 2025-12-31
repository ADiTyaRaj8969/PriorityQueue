"""
Task: Connect N ropes with minimum cost
Time Complexity: O(n log n)
Space Complexity: O(n)
"""

import heapq

def min_cost(ropes):
    heapq.heapify(ropes)
    cost = 0
    while len(ropes) > 1:
        a = heapq.heappop(ropes)
        b = heapq.heappop(ropes)
        cost += a + b
        heapq.heappush(ropes, a+b)
    return cost

print('Min cost:', min_cost([4,3,2,6]))
