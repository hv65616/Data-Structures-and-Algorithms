// PostOrder and Inorder array are given create a binary tree from it
// Algo: -
// We will start to select the element from last then create its node and search it in inorder array
// Once we find the location of very last element in inorder we return it position to get the left side and right side of tree
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

int search(int inOrder[], int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inOrder[i] == curr)
        {
            return i;
        }
    }
    return -1;
}
Node *buildTree(int postOrder[], int inOrder[], int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    static int index = 4;
    int curr = postOrder[index];
    index--;

    Node *node = new Node(curr);

    if (start == end)
    {
        return node;
    }

    int pos = search(inOrder, start, end, curr);

    node->right = buildTree(postOrder, inOrder, pos + 1, end);
    node->left = buildTree(postOrder, inOrder, start, pos - 1);

    return node;
}
void displayBuildTree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    displayBuildTree(root->left);
    cout << root->data << " ";
    displayBuildTree(root->right);
}
int main()
{
    int postOrder[] = {4, 2, 5, 3, 1};
    int inOrder[] = {4, 2, 1, 5, 3};
    Node *root = buildTree(postOrder, inOrder, 0, 4);
    displayBuildTree(root);
    return 0;
}