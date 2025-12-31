/*
 Task: Find top K largest numbers from a stream (real-time input)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int K = 3;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> stream = {4, 5, 2, 10, 8, 6};
    for (int x : stream)
    {
        pq.push(x);
        if ((int)pq.size() > K)
            pq.pop();
        // current top K
        vector<int> t;
        auto tmp = pq;
        while (!tmp.empty())
        {
            t.push_back(tmp.top());
            tmp.pop();
        }
        reverse(t.begin(), t.end());
        cout << "Top K so far: ";
        for (int v : t) cout << v << " ";
        cout << '\n';
    }
    return 0;
}

// Time Complexity: O(log K) per element
// Space Complexity: O(K)
