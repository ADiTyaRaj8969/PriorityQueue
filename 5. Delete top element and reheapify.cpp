/*
 Task: Delete the top element and re-heapify
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {10, 4, 7, 2, 9};
    make_heap(a.begin(), a.end());  // max-heap
    cout << "Before pop (heap array): ";
    for (int x : a) cout << x << " ";
    cout << '\n';
    pop_heap(a.begin(), a.end());
    a.pop_back();  // remove top
    cout << "After pop (heap array): ";
    for (int x : a) cout << x << " ";
    cout << '\n';
    return 0;
}

// Time Complexity: O(log n) for pop_heap
// Space Complexity: O(1) extra
