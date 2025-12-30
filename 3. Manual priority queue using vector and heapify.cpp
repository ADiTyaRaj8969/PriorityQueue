/*
 Task: Implement a priority queue manually using a vector and heapify logic
*/

#include <bits/stdc++.h>
using namespace std;

class MinPQ
{
   public:
    vector<int> a;
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
    vector<int> vals = {5, 2, 9, 1, 6};
    for (int v : vals) pq.push(v);
    cout << "MinPQ order: ";
    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(log n) per push/pop; building via make_heap O(n)
// Space Complexity: O(n)
