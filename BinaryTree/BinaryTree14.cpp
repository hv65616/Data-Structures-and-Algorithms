// //Lowest Common Ancestor
// First check whether the root data is equal to n1 and n2 if so then return root and if not so then make call for leftside of root and then rightside of root
// We will store these call values inside a node pointer
// After that we will check these leftside and rightside if these both are true then return root otherwise return leftside when leftside is not equal to null and rightside when rightside are not null
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

Node *LCA2(Node *root, int n1, int n2)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == n1 || root->data == n2)
    {
        return root;
    }

    Node *leftSide = LCA2(root->left, n1, n2);
    Node *rightSide = LCA2(root->right, n1, n2);

    if (leftSide && rightSide)
    {
        return root;
    }
    if (leftSide != NULL)
    {
        return leftSide;
    }
    return rightSide;
}
int main()
{
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);

    int n1 = 7;
    int n2 = 6;
    Node *lca = LCA2(root, n1, n2);
    if (lca == NULL)
    {
        cout << "LCA Does not exist" << endl;
    }
    else
    {
        cout << "LCA: " << lca->data << endl;
    }
    return 0;
}