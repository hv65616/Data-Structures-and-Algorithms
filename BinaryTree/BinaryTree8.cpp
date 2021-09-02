// Find the height of binary tree
// In this we will recursive the function first for left side of tree and after that right side of tree
// At last we will add both with 1 and that 1 is the current node
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

int heightOfTree(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSide = heightOfTree(root->left);
    int rightSide = heightOfTree(root->right);
    return max(leftSide, rightSide) + 1;
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
    cout << heightOfTree(root);
    return 0;
}