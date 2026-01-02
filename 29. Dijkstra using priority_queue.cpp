/*
 Task: Implement Dijkstra's shortest path algorithm using a priority queue
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& adj, int src)
{
    const int INF = 1e9;
    vector<int> dist(n, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u])
            continue;
        for (auto& e : adj[u])
        {
            int v = e.first, w = e.second;
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main()
{
    int n = 5;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 9});
    adj[0].push_back({2, 6});
    adj[0].push_back({3, 5});
    adj[2].push_back({3, 2});
    adj[2].push_back({1, 2});
    auto d = dijkstra(n, adj, 0);
    for (int i = 0; i < n; ++i) cout << d[i] << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(E log V)
// Space Complexity: O(V)
