//Finding the maximun element in Binary Search Tree
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

int maxElement(Node *root)
{
    if (root == NULL)
    {
        return -1;
    }
    else if (root->right == NULL)
    {
        return root->data;
    }
    return maxElement(root->right);
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(16);
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(13);
    cout << maxElement(root) << endl;
}