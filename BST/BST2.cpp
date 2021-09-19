//Search in BST for a particular key
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

Node *searchInBST(Node *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {
        return root;
    }
    if (root->data < val)
    {
        return searchInBST(root->right, val);
    }
    return searchInBST(root->left, val);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(6);

    if (searchInBST(root, 5) == NULL)
    {
        cout << "Key Doesn't exist";
    }
    else
    {
        cout << "Key exist";
    }

    return 0;
}