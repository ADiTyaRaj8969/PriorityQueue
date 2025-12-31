/*
 Task: Rearrange characters in a string so no two adjacent characters are the same
*/

#include <bits/stdc++.h>
using namespace std;

string rearrange(string s)
{
    unordered_map<char, int> cnt;
    for (char c : s) cnt[c]++;
    priority_queue<pair<int, char>> pq;  // max-heap by frequency
    for (auto& p : cnt) pq.push({p.second, p.first});
    string res;
    pair<int, char> prev = {0, '#'};
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        res.push_back(cur.second);
        if (prev.first > 0)
            pq.push(prev);
        cur.first--;
        prev = cur;
    }
    if (res.size() != s.size())
        return "";  // impossible
    return res;
}

int main()
{
    string s = "aaabc";
    cout << "Rearranged: " << rearrange(s) << '\n';
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(k)
