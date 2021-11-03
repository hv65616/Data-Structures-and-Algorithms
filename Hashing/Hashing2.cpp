//Vertical Order Print
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

void getVerticalOrder(Node *root, int hdis, map<int, vector<int>> &mp)
{
    if (root == NULL)
    {
        return;
    }
    mp[hdis].push_back(root->data);
    getVerticalOrder(root->left, hdis - 1, mp);
    getVerticalOrder(root->right, hdis + 1, mp);
}
int main()
{
    struct Node *root = new Node(10);
    root->left = new Node(7);
    root->right = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(11);
    root->right->left = new Node(14);
    root->right->right = new Node(6);

    map<int, vector<int>> mp;
    int hdis = 0;

    getVerticalOrder(root, hdis, mp);

    map<int, vector<int>>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        for (int i = 0; i < (it->second).size(); i++)
        {
            cout << (it->second)[i] << " ";
        }
        cout << endl;
    }
    return 0;
}