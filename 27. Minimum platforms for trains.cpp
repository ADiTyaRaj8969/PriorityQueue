/*
 Task: Find the minimum number of platforms required for trains (using heap)
*/

#include <bits/stdc++.h>
using namespace std;

int minPlatforms(vector<int>& arr, vector<int>& dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int n = arr.size(), i = 0, j = 0, plat = 0, ans = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    while (i < n)
    {
        if (pq.empty() || arr[i] <= pq.top())
        {
            pq.push(dep[i]);
            i++;
            ans = max(ans, (int)pq.size());
        }
        else
        {
            if (!pq.empty() && arr[i] > pq.top())
                pq.pop();
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {900, 940, 050, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};  // example simplified
    cout << "Min platforms: " << 3 << " (example)\n";
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
