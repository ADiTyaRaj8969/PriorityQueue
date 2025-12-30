/*
 Task: Convert an array into a heap (make_heap in STL)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {4, 1, 7, 3, 9};
    make_heap(a.begin(), a.end());  // makes a max-heap by default
    cout << "Max-heap after make_heap: ";
    for (int x : a) cout << x << " ";
    cout << '\n';
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1) extra
