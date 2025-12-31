/*
 Task: Find the smallest range covering elements from K sorted lists
*/

#include <bits/stdc++.h>
using namespace std;

// We'll push (val, list_index, idx_in_list)
int main()
{
    vector<vector<int>> lists = {{4, 10, 15, 24, 26}, {0, 9, 12, 20}, {5, 18, 22, 30}};
    int k = lists.size();
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    int curMax = INT_MIN;
    for (int i = 0; i < k; ++i)
    {
        pq.push({lists[i][0], i, 0});
        curMax = max(curMax, lists[i][0]);
    }

    int bestL = -1, bestR = INT_MAX;
    while (true)
    {
        auto [val, li, idx] = pq.top();
        pq.pop();
        if (curMax - val < bestR - bestL)
        {
            bestL = val;
            bestR = curMax;
        }
        if (idx + 1 == (int)lists[li].size())
            break;
        int nextVal = lists[li][idx + 1];
        pq.push({nextVal, li, idx + 1});
        curMax = max(curMax, nextVal);
    }

    cout << "Smallest range: [" << bestL << ", " << bestR << "]\n";
    return 0;
}

// Time Complexity: O(N log k) total elements N
// Space Complexity: O(k)
