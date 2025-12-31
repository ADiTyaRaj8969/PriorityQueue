/*
 Task: Find sum of elements between K1-th and K2-th smallest elements
*/

#include <bits/stdc++.h>
using namespace std;

int sumBetweenK1K2(vector<int>& a, int k1, int k2)
{
    priority_queue<int> pq;  // max-heap of size k2-1
    for (int x : a)
    {
        pq.push(x);
        if ((int)pq.size() > k2 - 1)
            pq.pop();
    }
    int sum = 0;
    // now extract elements between k1 and k2
    // simplest: sort and sum
    sort(a.begin(), a.end());
    for (int i = k1; i < k2 - 1 && i < (int)a.size(); ++i) sum += a[i];
    return sum;
}

int main()
{
    vector<int> a = {1, 3, 12, 5, 15, 11};
    cout << "Sum between 3rd and 6th smallest: " << sumBetweenK1K2(a, 3, 6) << '\n';
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(1) extra
