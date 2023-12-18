// Bottom view of binary tree
// To find the bottom view of the binary tree the code will remain exactly same of the top view of the bianry tree the only difference is that we update the particular level with the most recent node value because that value is the top node from bottom
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
vector<int> bottomview(Node *root)
{
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    vector<int> res;
    while (q.empty() != true)
    {
        Node *node = q.front().first;
        int level = q.front().second;
        q.pop();
        mp[level] = node->data;
        if (node->left != NULL)
        {
            q.push({node->left, level - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, level + 1});
        }
    }
    for (auto i : mp)
    {
        res.push_back(i.second);
    }
    return res;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    vector<int> ans = bottomview(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}