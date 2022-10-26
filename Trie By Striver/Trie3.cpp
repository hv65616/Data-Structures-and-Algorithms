// Longest word with all perfixes
// Output - ninja
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;
    bool containskey(char ch)
    {
        return links[ch - 'a'];
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void put(Node *node, char ch)
    {
        links[ch - 'a'] = node;
    }
    void setend()
    {
        flag = true;
    }
    bool isend()
    {
        return flag;
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
    void insert(string str)
    {
        Node *node = root;
        int len = str.length();
        for (int i = 0; i < len; i++)
        {
            if (node->containskey(str[i]) == false)
            {
                node->put(new Node(), str[i]);
            }
            node = node->get(str[i]);
        }
        node->setend();
    }
    bool checkprefixexists(string str)
    {
        bool flag = true;
        Node *node = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (node->containskey(str[i]) == true)
            {
                node = node->get(str[i]);
                flag = flag & node->isend();
            }
            else
            {
                return false;
            }
        }
        return flag;
    }
};
string completeString(int n, vector<string> &str)
{
    Trie *trie = new Trie();
    for (auto it : str)
    {
        trie->insert(it);
    }
    string longest = "";
    for (auto it : str)
    {
        if (trie->checkprefixexists(it))
        {
            if (it.length() > longest.length())
            {
                longest = it;
            }
            else if (it.length() == longest.length() && it < longest)
            {
                longest = it;
            }
        }
    }
    if (longest == "")
        return "NONE";
    return longest;
}
int main()
{
    int n = 6;
    vector<string> str = {"n", "ni", "nin", "ninj", "ninja", "ninga"};
    string ans = completeString(n, str);
    cout << ans << endl;
    return 0;
}