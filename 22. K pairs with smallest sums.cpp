/*
 Task: Find k pairs with smallest sums from two sorted arrays
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int>& A, vector<int>& B, int k)
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < (int)A.size() && i < k; ++i) pq.push({A[i] + B[0], {i, 0}});
    vector<pair<int, int>> res;
    while (k-- && !pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        int i = t.second.first, j = t.second.second;
        res.push_back({A[i], B[j]});
        if (j + 1 < (int)B.size())
            pq.push({A[i] + B[j + 1], {i, j + 1}});
    }
    return res;
}

int main()
{
    vector<int> A = {1, 7, 11};
    vector<int> B = {2, 4, 6};
    auto r = kSmallestPairs(A, B, 3);
    for (auto& p : r) cout << "(" << p.first << "," << p.second << ") ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(k log k)
// Space Complexity: O(k)
