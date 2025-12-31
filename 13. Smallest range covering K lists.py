"""
Task: Find the smallest range covering elements from K sorted lists
Time Complexity: O(N log k)
Space Complexity: O(k)
"""

import heapq

lists = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
pq = []
cur_max = -10**9
for i,l in enumerate(lists):
    heapq.heappush(pq, (l[0], i, 0))
    cur_max = max(cur_max, l[0])

best_l, best_r = -1, 10**9
while pq:
    val, li, idx = heapq.heappop(pq)
    if cur_max - val < best_r - best_l:
        best_l, best_r = val, cur_max
    if idx+1 >= len(lists[li]): break
    nextv = lists[li][idx+1]
    heapq.heappush(pq, (nextv, li, idx+1))
    cur_max = max(cur_max, nextv)

print('Smallest range:', (best_l, best_r))
