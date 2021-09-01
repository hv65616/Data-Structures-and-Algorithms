// Implementation of Level Order Tranversal
// Find the the sum of binary tree at k level of nodes
// The code will be exact same just like the level order tranversal
// The only change is in place of displaying the data present at each level we will traverse upto that level then find the sum at that level of nodes
// Till then we will constantly adding all the elements in queue and will be removing it
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

int sumAtKLevel(Node *root, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    int sum = 0;
    int level = 0;
    while (q.empty() != true)
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            if (level == k)
            {
                sum = sum + node->data;
            }
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (q.empty() != true)
        {
            q.push(NULL);
            level++;
        }
    }
    return sum;
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
    cout << sumAtKLevel(root, 2) << endl;
    return 0;
}