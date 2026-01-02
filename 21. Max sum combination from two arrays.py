"""
Task: Find the maximum sum combination from two arrays
Time Complexity: O(k log k)
Space Complexity: O(k)
"""

import heapq

def max_sum_combinations(A,B,k):
    A.sort(reverse=True); B.sort(reverse=True)
    pq=[]; seen=set(); res=[]
    pq.append((-(A[0]+B[0]), 0,0)); seen.add((0,0))
    heapq.heapify(pq)
    while k and pq:
        s,i,j = heapq.heappop(pq); s=-s
        res.append((A[i], B[j])); k-=1
        if i+1 < len(A) and (i+1,j) not in seen: heapq.heappush(pq, (-(A[i+1]+B[j]), i+1, j)); seen.add((i+1,j))
        if j+1 < len(B) and (i,j+1) not in seen: heapq.heappush(pq, (-(A[i]+B[j+1]), i, j+1)); seen.add((i,j+1))
    return res

print('Top combos:', max_sum_combinations([4,2,5,1],[8,0,3,5],3))
