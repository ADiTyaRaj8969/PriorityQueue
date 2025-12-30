/*
 Task: Create min-heap and max-heap using priority_queue
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {5, 1, 8, 3, 7};

    // Max-heap (default)
    priority_queue<int> maxh(a.begin(), a.end());

    // Min-heap
    priority_queue<int, vector<int>, greater<int>> minh(a.begin(), a.end());

    cout << "Max-heap (pop order): ";
    while (!maxh.empty())
    {
        cout << maxh.top() << " ";
        maxh.pop();
    }
    cout << '\n';

    cout << "Min-heap (pop order): ";
    while (!minh.empty())
    {
        cout << minh.top() << " ";
        minh.pop();
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(n) to build from range, O(log n) per push/pop
// Space Complexity: O(n)
