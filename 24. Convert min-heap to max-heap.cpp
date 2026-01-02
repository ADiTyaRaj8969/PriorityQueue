/*
 Task: Convert min-heap to max-heap (and vice versa)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 3, 5, 7, 9};  // assume min-heap array
    // to convert to max-heap array, we can invert values or rebuild
    // rebuild as max-heap
    make_heap(a.begin(), a.end());
    cout << "Converted to max-heap array: ";
    for (int x : a) cout << x << " ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
