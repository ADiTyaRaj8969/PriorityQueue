/*
 Task: Merge K sorted arrays using a min-heap
*/

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int val;
    int ai;
    int idx;
};  // value, which array, index

int main()
{
    vector<vector<int>> lists = {{1, 4, 7}, {2, 5, 8}, {3, 6, 9}};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    for (int i = 0; i < (int)lists.size(); ++i)
        if (!lists[i].empty())
            pq.push({lists[i][0], {i, 0}});

    vector<int> out;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int val = top.first;
        int ai = top.second.first;
        int idx = top.second.second;
        out.push_back(val);
        if (idx + 1 < (int)lists[ai].size())
            pq.push({lists[ai][idx + 1], {ai, idx + 1}});
    }

    cout << "Merged: ";
    for (int x : out) cout << x << " ";
    cout << '\n';
    return 0;
}

// Time Complexity: O(N log k) where N total elements, k lists
// Space Complexity: O(k)
