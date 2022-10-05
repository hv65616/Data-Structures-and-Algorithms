// Implementation Of Trie
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    bool flag = false;
    bool containskey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
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
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containskey(word[i]))
            {
                node->put(word[i], new Node());
            }
            // move to reference trie
            node = node->get(word[i]);
        }
        node->setend();
    }
    bool search(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containskey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }
        return node->isend();
    }
    bool startswith(string str)
    {
        Node *node = root;
        for (int i = 0; i < str.length(); i++)
        {
            if (!node->containskey(str[i]))
            {
                return false;
            }
            node = node->get(str[i]);
        }
        return true;
    }
};
int main()
{
    int n = 5;
    vector<int> type = {1, 1, 2, 3, 2};
    vector<string> value = {"hello", "help", "help", "hel", "hel"};
    Trie trie;
    for (int i = 0; i < n; i++)
    {
        if (type[i] == 1)
        {
            trie.insert(value[i]);
        }
        else if (type[i] == 2)
        {
            if (trie.search(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
        else
        {
            if (trie.startswith(value[i]))
            {
                cout << "true"
                     << "\n";
            }
            else
            {
                cout << "false"
                     << "\n";
            }
        }
    }
    return 0;
}