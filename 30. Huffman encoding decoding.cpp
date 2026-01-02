/*
 Task: Implement Huffman Encoding and Decoding using Min-Heap
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    char ch;
    int freq;
    Node *l, *r;
    Node(char c, int f) : ch(c), freq(f), l(nullptr), r(nullptr) {}
};
struct Cmp
{
    bool operator()(Node* a, Node* b) const { return a->freq > b->freq; }
};

void buildCodes(Node* root, string s, unordered_map<char, string>& mp)
{
    if (!root)
        return;
    if (!root->l && !root->r)
        mp[root->ch] = s;
    buildCodes(root->l, s + "0", mp);
    buildCodes(root->r, s + "1", mp);
}

int main()
{
    string data = "aaabbc";
    unordered_map<char, int> cnt;
    for (char c : data) cnt[c]++;
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (auto& p : cnt) pq.push(new Node(p.first, p.second));
    while (pq.size() > 1)
    {
        Node* a = pq.top();
        pq.pop();
        Node* b = pq.top();
        pq.pop();
        Node* r = new Node('\0', a->freq + b->freq);
        r->l = a;
        r->r = b;
        pq.push(r);
    }
    Node* root = pq.top();
    unordered_map<char, string> mp;
    buildCodes(root, "", mp);
    cout << "Codes:\n";
    for (auto& p : mp) cout << p.first << ":" << p.second << "\n";
    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
