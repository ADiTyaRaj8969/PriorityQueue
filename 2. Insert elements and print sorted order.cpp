/*
 Task: Insert elements into a priority queue and print in sorted order
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> pq;  // min-heap
    vector<int> data = {4, 1, 7, 3, 9};
    for (int x : data) pq.push(x);

    cout << "Sorted order (ascending): ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
