// Maximum XOR
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[2];
    bool containskey(int bit)
    {
        return (links[bit] != NULL);
    }
    Node *get(int bit)
    {
        return links[bit];
    }
    void put(int bit, Node *node)
    {
        links[bit] = node;
    }
};
class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containskey(bit)==false)
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }
    int getmax(int num)
    {
        Node *node = root;
        int maxnum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containskey(!bit))
            {
                maxnum = maxnum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxnum;
    }
};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    Trie trie;
    for(auto &it : arr1)
    {
        trie.insert(it);
    }
    int max1 = 0;
    for(auto &it : arr2)
    {
        max1 = max(max1,trie.getmax(it));
    }
    return max1;
}
int main()
{
    vector<int> arr1 = {6, 8};
    vector<int> arr2 = {7, 8, 2};
    int n = 2, m = 3;
    cout << maxXOR(n, m, arr1, arr2) << endl;
    return 0;
}