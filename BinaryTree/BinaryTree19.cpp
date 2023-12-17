// Top view of binary tree
// For finding the top view of bianry tree consider the left half as negative side of level and right half as positive side of level and then we simply follow the level order traversal. We need to check if that particular level has already been visited that means it outermost node has been stored and no need to update the value
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
vector<int> topview(Node *root)
{
    vector<int> ans;
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (q.empty() != true)
    {
        Node *node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (mp.find(level) == mp.end())
        {
            mp[level] = node->data;
        }
        if (node->left != NULL)
        {
            q.push({node->left, level - 1});
        }
        if (node->right != NULL)
        {
            q.push({node->right, level + 1});
        }
    }
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
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
    vector<int> ans = topview(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}