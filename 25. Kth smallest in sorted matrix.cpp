/*
 Task: Find the kth smallest element in a sorted matrix (rows and cols sorted)
*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallestMatrix(vector<vector<int>>& mat, int k)
{
    int n = mat.size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for (int i = 0; i < n; ++i) pq.push({mat[i][0], i, 0});
    int val = -1;
    while (k--)
    {
        auto [v, i, j] = pq.top();
        pq.pop();
        val = v;
        if (j + 1 < (int)mat[i].size())
            pq.push({mat[i][j + 1], i, j + 1});
    }
    return val;
}

int main()
{
    vector<vector<int>> m = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    cout << kthSmallestMatrix(m, 8) << "\n";
    return 0;
}

// Time Complexity: O(k log n)
// Space Complexity: O(n)
