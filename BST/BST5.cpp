//Finding the minimum element from the binary search tree
#include <iostream>
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

int minElement(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->left == NULL)
    {
        return root->data;
    }
    return minElement(root->left);
}


int main()
{
    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(16);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(13);
    cout << minElement(root) << endl;
    return 0;
}