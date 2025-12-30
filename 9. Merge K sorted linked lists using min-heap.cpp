/*
 Task: Merge K sorted linked lists using a min-heap
*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};
struct Cmp
{
    bool operator()(Node* a, Node* b) const { return a->val > b->val; }
};

int main()
{
    // build three small lists
    Node* a = new Node(1);
    a->next = new Node(4);
    a->next->next = new Node(7);
    Node* b = new Node(2);
    b->next = new Node(5);
    b->next->next = new Node(8);
    Node* c = new Node(3);
    c->next = new Node(6);
    c->next->next = new Node(9);

    vector<Node*> lists = {a, b, c};
    priority_queue<Node*, vector<Node*>, Cmp> pq;
    for (Node* L : lists)
        if (L)
            pq.push(L);

    Node dummy(0);
    Node* tail = &dummy;
    while (!pq.empty())
    {
        Node* t = pq.top();
        pq.pop();
        tail->next = new Node(t->val);
        tail = tail->next;
        if (t->next)
            pq.push(t->next);
    }

    cout << "Merged list: ";
    Node* it = dummy.next;
    while (it)
    {
        cout << it->val << " ";
        it = it->next;
    }
    cout << '\n';
    return 0;
}

// Time Complexity: O(N log k)
// Space Complexity: O(k + N)
