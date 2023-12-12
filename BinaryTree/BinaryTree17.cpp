// Morris Inorder Traversal
// We connect the left subtree righmost node to the curr tree root node and then traverse the tree left part as we reach to the null we simply insert that and move back to the root and then check whether its left subtree node is connected to root if so simply dilink and insert the root to array and move the right side
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

vector<int> morrisinorder(Node *root)
{
    vector<int> ans;
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *move = curr->left;
            while (move->right && move->right != curr)
            {
                move = move->right;
            }
            if (move->right == NULL){
                move->right = curr;
                curr = curr->left;
            }else{
                move->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
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
    vector<int> ans = morrisinorder(root);
    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}