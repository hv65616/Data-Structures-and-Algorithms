// Find out whether the binary tree is balanced or not
// The balanced tree is one where the difference between left side and right side of tree is less than or equal to one 
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
    int ls = heightOfTree(root->left);
    int rs = heightOfTree(root->right);
    return max(ls, rs) + 1;
}
bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }
    if (isBalanced(root->left) == false)
    {
        return true;
    }
    if (isBalanced(root->right) == false)
    {
        return true;
    }
    int lh = heightOfTree(root->left);
    int rh = heightOfTree(root->right);
    if (abs(lh - rh) <= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
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
    if (isBalanced(root))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Not Balanced Tree" << endl;
    }

    struct Node *root2 = new Node(1);
    root2->left = new Node(2);
    root2->left->left = new Node(3);
    if (isBalanced(root2))
    {
        cout << "Balanced Tree" << endl;
    }
    else
    {
        cout << "Not Balanced Tree" << endl;
    }
    return 0;
}