/*
 Task: Find the top K closest points to origin (2D plane)
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kClosest(vector<pair<int, int>>& pts, int k)
{
    priority_queue<pair<int, pair<int, int>>> pq;  // max-heap by dist
    for (auto& p : pts)
    {
        int d = p.first * p.first + p.second * p.second;
        pq.push({d, p});
        if ((int)pq.size() > k)
            pq.pop();
    }
    vector<pair<int, int>> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    return res;
}

int main()
{
    vector<pair<int, int>> pts = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    auto r = kClosest(pts, 2);
    for (auto& p : r) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
