/*
 Task: Check if a given array represents a valid max-heap
*/

#include <bits/stdc++.h>
using namespace std;

bool isMaxHeap(const vector<int>& a)
{
    int n = a.size();
    for (int i = 0; i <= (n - 2) / 2; ++i)
    {
        if (2 * i + 1 < n && a[i] < a[2 * i + 1])
            return false;
        if (2 * i + 2 < n && a[i] < a[2 * i + 2])
            return false;
    }
    return true;
}

int main()
{
    vector<int> a = {90, 15, 10, 7, 12, 2, 7, 3};
    cout << (isMaxHeap(a) ? "Yes" : "No") << "\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
