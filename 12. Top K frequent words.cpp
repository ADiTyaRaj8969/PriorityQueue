/*
 Task: Return the K most frequent words from a list of strings
*/

#include <bits/stdc++.h>
using namespace std;

vector<string> topKWords(vector<string>& words, int k)
{
    unordered_map<string, int> cnt;
    for (auto& w : words) cnt[w]++;
    auto cmp = [](const pair<int, string>& a, const pair<int, string>& b)
    {
        if (a.first != b.first)
            return a.first > b.first;  // min-heap on freq
        return a.second < b.second;
    };
    priority_queue<pair<int, string>, vector<pair<int, string>>, decltype(cmp)> pq(cmp);
    for (auto& p : cnt)
    {
        pq.push({p.second, p.first});
        if ((int)pq.size() > k)
            pq.pop();
    }
    vector<string> res;
    while (!pq.empty())
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<string> w = {"i", "love", "leetcode", "i", "love", "coding"};
    auto r = topKWords(w, 2);
    cout << "Top words: ";
    for (auto& s : r) cout << s << " ";
    cout << '\n';
    return 0;
}

// Time Complexity: O(n log k)
// Space Complexity: O(n)
