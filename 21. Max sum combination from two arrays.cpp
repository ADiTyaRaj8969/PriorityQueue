/*
 Task: Find the maximum sum combination from two arrays
*/

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> maxSumCombinations(vector<int>& A, vector<int>& B, int k)
{
    sort(A.rbegin(), A.rend());
    sort(B.rbegin(), B.rend());
    priority_queue<tuple<int, int, int>> pq;
    set<pair<int, int>> seen;
    vector<pair<int, int>> res;
    pq.push({A[0] + B[0], 0, 0});
    seen.insert({0, 0});
    while (k-- && !pq.empty())
    {
        auto [sum, i, j] = pq.top();
        pq.pop();
        res.push_back({A[i], B[j]});
        if (i + 1 < (int)A.size() && !seen.count({i + 1, j}))
        {
            pq.push({A[i + 1] + B[j], i + 1, j});
            seen.insert({i + 1, j});
        }
        if (j + 1 < (int)B.size() && !seen.count({i, j + 1}))
        {
            pq.push({A[i] + B[j + 1], i, j + 1});
            seen.insert({i, j + 1});
        }
    }
    return res;
}

int main()
{
    vector<int> A = {4, 2, 5, 1};
    vector<int> B = {8, 0, 3, 5};
    auto r = maxSumCombinations(A, B, 3);
    cout << "Top combos:\n";
    for (auto& p : r) cout << p.first << "," << p.second << "\n";
    return 0;
}

// Time Complexity: O(k log k)
// Space Complexity: O(k)
