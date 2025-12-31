/*
 Task: Implement a Max Priority Queue class using arrays (custom)
*/

#include <bits/stdc++.h>
using namespace std;

class MaxPQ
{
    vector<int> a;

   public:
    void push(int x)
    {
        a.push_back(x);
        push_heap(a.begin(), a.end());
    }
    int top() { return a.front(); }
    void pop()
    {
        pop_heap(a.begin(), a.end());
        a.pop_back();
    }
    bool empty() { return a.empty(); }
};

int main()
{
    MaxPQ pq;
    pq.push(3);
    pq.push(1);
    pq.push(5);
    cout << "Top: " << pq.top() << "\n";
    pq.pop();
    cout << "Top after pop: " << pq.top() << "\n";
    return 0;
}

// Time Complexity: O(log n) per push/pop
// Space Complexity: O(n)
