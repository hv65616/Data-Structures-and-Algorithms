// Nodes at given distance in binary tree
// GFG - https://practice.geeksforgeeks.org/problems/nodes-at-given-distance-in-binary-tree/1
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

Node *target = NULL;
void makepar(Node *root, unordered_map<Node *, Node *> &ump, int tar)
{
    queue<Node *> q;
    q.push(root);
    while (q.empty() != true)
    {
        Node *node = q.front();
        q.pop();
        if (node->data == tar)
        {
            target = node;
        }
        if (node->left != NULL)
        {
            ump[node->left] = node;
            q.push(node->left);
        }
        if (node->right != NULL)
        {
            ump[node->right] = node;
            q.push(node->right);
        }
    }
}
vector<int> Kdistancenodes(Node *root, int tar, int k)
{
    vector<int> ans;
    unordered_map<Node *, Node *> ump;
    makepar(root, ump, tar);
    queue<Node *> q;
    unordered_map<Node *, bool> vis;
    int cnt = 0;
    q.push(target);
    vis[target] = true;
    while (q.empty() != true)
    {
        if (cnt == k)
            break;
        int sz = q.size();
        while (sz--)
        {
            Node *node = q.front();
            q.pop();
            if (node->left != NULL && vis[node->left] != true)
            {
                q.push(node->left);
                vis[node->left] = true;
            }
            if (node->right != NULL && vis[node->right] != true)
            {
                q.push(node->right);
                vis[node->right] = true;
            }
            if (ump[node] != NULL && vis[ump[node]] != true)
            {
                q.push(ump[node]);
                vis[ump[node]] = true;
            }
        }
        cnt++;
    }
    while (q.empty() != true)
    {
        ans.push_back(q.front()->data);
        q.pop();
    }
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    struct Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    vector<int> ans = Kdistancenodes(root, 8, 2);
    for (auto it : ans)
        cout << it << " ";
    return 0;
}