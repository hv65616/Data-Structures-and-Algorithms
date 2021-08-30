// Preorder and Inorder array are given now create a binary tree form it
// Algo:- From the preorder array select the element at idx = 0 , create a node of it and search for it in inorder array
// If it found return it index in inorder so that we get the range from start to index left side of tree is and from index to end right side of tree is present
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

int search(int inorder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}

Node *buildTree(int preorder[], int inorder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int index = 0;
    int curr = preorder[index];
    index++;
    Node *node = new Node(curr);
    if (start == end)
    {
        return node;
    }
    int pos = search(inorder, start, end, curr);

    node->left = buildTree(preorder, inorder, start, pos - 1);
    node->right = buildTree(preorder, inorder, pos + 1, end);

    return node;
}

void displayTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    displayTree(root->left);
    cout << root->data << " ";
    displayTree(root->right);
}
int main()
{
    int preorder[] = {1, 2, 4, 3, 5};
    int inorder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(preorder, inorder, 0, 4);
    displayTree(root);
    return 0;
}