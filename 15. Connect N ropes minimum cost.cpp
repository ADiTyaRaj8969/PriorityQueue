/*
 Task: Connect N ropes with minimum cost
*/

#include <bits/stdc++.h>
using namespace std;

long long minCostConnectRopes(vector<int>& ropes)
{
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int r : ropes) pq.push(r);
    long long cost = 0;
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        cost += a + b;
        pq.push(a + b);
    }
    return cost;
}

int main()
{
    vector<int> ropes = {4, 3, 2, 6};
    cout << "Min cost: " << minCostConnectRopes(ropes) << '\n';
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
