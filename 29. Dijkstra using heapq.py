"""
Task: Implement Dijkstra's shortest path algorithm using a priority queue
Time Complexity: O(E log V)
Space Complexity: O(V)
"""

import heapq

def dijkstra(n, adj, src):
    INF = 10**9
    dist = [INF]*n
    dist[src]=0
    pq=[(0,src)]
    while pq:
        d,u = heapq.heappop(pq)
        if d>dist[u]: continue
        for v,w in adj[u]:
            if dist[v] > d + w:
                dist[v] = d + w
                heapq.heappush(pq, (dist[v], v))
    return dist

adj = {0: [(1,9),(2,6),(3,5)], 2: [(3,2),(1,2)]}
print(dijkstra(5, adj, 0))
