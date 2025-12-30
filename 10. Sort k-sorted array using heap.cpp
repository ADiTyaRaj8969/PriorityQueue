/*
 Task: Sort a nearly sorted (k-sorted) array using a heap
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> sortKSorted(vector<int>& a, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> res;
    for (int i = 0; i < (int)a.size(); ++i)
    {
        pq.push(a[i]);
        if ((int)pq.size() > k)
        {
            res.push_back(pq.top());
            pq.pop();
        }
    }
    while (!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }
    return res;
}

int main()
{
    vector<int> a = {3, 2, 6, 5, 4, 8};
    auto b = sortKSorted(a, 2);
    cout << "Sorted: ";
    for (int x : b) cout << x << " ";
    cout << '\n';
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
