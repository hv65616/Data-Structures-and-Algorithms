//Printing the level order tranversal of Binary Tree
//Level Order Tranversal of Binary Tree gives us the Heap that can be min heap or max heap
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

void levelOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.empty() != true)
    {
        Node *node = q.front();
        q.pop();
        if (node != NULL)
        {
            cout << node->data << " ";
            if (node->left != NULL)
            {
                q.push(node->left);
            }
            if (node->right != NULL)
            {
                q.push(node->right);
            }
        }
        else if (q.empty() != NULL)
        {
            q.push(NULL);
        }
    }
}
int main()
{
    struct Node *root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->left->right = new Node(5);
    root->right->left = new Node(20);
    root->right->right = new Node(30);
    levelOrder(root);
    return 0;
}