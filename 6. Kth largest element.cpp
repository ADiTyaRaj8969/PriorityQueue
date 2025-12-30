/*
 Task: Find the kth largest element in an array
*/

#include <bits/stdc++.h>
using namespace std;

int kthLargest(vector<int>& a, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int x : a)
    {
        pq.push(x);
        if ((int)pq.size() > k)
            pq.pop();
    }
    return pq.top();
}

int main()
{
    vector<int> a = {3, 2, 1, 5, 6, 4};
    cout << "2nd largest: " << kthLargest(a, 2) << '\n';
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
