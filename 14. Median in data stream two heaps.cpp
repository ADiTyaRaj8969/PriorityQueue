/*
 Task: Find median in a data stream using two heaps
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> lowers;                              // max-heap
    priority_queue<int, vector<int>, greater<int>> highers;  // min-heap
    vector<int> stream = {5, 15, 1, 3};
    for (int x : stream)
    {
        if (lowers.empty() || x < lowers.top())
            lowers.push(x);
        else
            highers.push(x);
        // rebalance
        if ((int)lowers.size() > (int)highers.size() + 1)
        {
            highers.push(lowers.top());
            lowers.pop();
        }
        else if ((int)highers.size() > (int)lowers.size() + 1)
        {
            lowers.push(highers.top());
            highers.pop();
        }

        double median;
        if (lowers.size() == highers.size())
            median = (lowers.top() + highers.top()) / 2.0;
        else
            median = lowers.size() > highers.size() ? lowers.top() : highers.top();
        cout << "Median so far: " << median << '\n';
    }
    return 0;
}

// Time Complexity: O(log n) per insertion
// Space Complexity: O(n)
