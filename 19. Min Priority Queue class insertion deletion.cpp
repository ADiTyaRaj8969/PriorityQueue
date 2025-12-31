/*
 Task: Implement a Min Priority Queue class with insertion and deletion
*/

#include <bits/stdc++.h>
using namespace std;

class MinPQ
{
    vector<int> a;

   public:
    void push(int x)
    {
        a.push_back(x);
        push_heap(a.begin(), a.end(), greater<int>());
    }
    int top() { return a.front(); }
    void pop()
    {
        pop_heap(a.begin(), a.end(), greater<int>());
        a.pop_back();
    }
    bool empty() { return a.empty(); }
};

int main()
{
    MinPQ pq;
    pq.push(4);
    pq.push(2);
    pq.push(9);
    cout << "Top(min): " << pq.top() << "\n";
    pq.pop();
    cout << "Top after pop: " << pq.top() << "\n";
    return 0;
}

// Time Complexity: O(log n) per push/pop
// Space Complexity: O(n)
