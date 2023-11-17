// Convert Binary Tree into CDLL
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
Node *head = NULL;
Node *tail = NULL;
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (tail == NULL)
    {
        head = root;
    }
    else
    {
        tail->right = root;
        root->left = tail;
    }
    tail = root;
    inorder(root->right);
}
Node *btreetocdll(Node *root)
{
    inorder(root);
    if (head != NULL && tail != NULL)
    {
        tail->right = head;
        head->left = tail;
    }
    return head;
}
int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    return 0;
}