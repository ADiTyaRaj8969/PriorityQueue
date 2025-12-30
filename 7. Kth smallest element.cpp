/*
 Task: Find the kth smallest element in an array
*/

#include <bits/stdc++.h>
using namespace std;

int kthSmallest(vector<int>& a, int k)
{
    priority_queue<int> pq;  // max-heap of size k
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
    vector<int> a = {7, 10, 4, 3, 20, 15};
    cout << "3rd smallest: " << kthSmallest(a, 3) << '\n';
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
