#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node *links[26];
    int countprefix = 0;
    int countend = 0;
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
    void increaseprefix()
    {
        countprefix++;
    }
    void increaseend()
    {
        countend++;
    }
    void deleteprefix()
    {
        countprefix--;
    }
    void deleteend()
    {
        countend--;
    }
    int getprefix()
    {
        return countprefix;
    }
    int getend()
    {
        return countend;
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
            node = node->get(word[i]);
            node->increaseprefix();
        }
        node->increaseend();
    }
    int countwordsequaltoo(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getend();
    }
    int countwordsstartingwith(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
            {
                return 0;
            }
        }
        return node->getprefix();
    }
    void erase(string &word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (node->containskey(word[i]))
            {
                node = node->get(word[i]);
                node->deleteprefix();
            }
            else
            {
                return;
            }
        }
        node->deleteend();
    }
};
int main()
{
    Trie T;
    T.insert("apple");
    T.insert("apple");
    T.insert("apps");
    T.insert("apps");
    string word1 = "apps";
    cout << "Count Words Equal to " << word1 << " " << T.countwordsequaltoo(word1) << endl;
    string word2 = "abc";
    cout << "Count Words Equal to " << word2 << " " << T.countwordsequaltoo(word2) << endl;
    string word3 = "ap";
    cout << "Count Words Starting With " << word3 << " " << T.countwordsstartingwith(word3)
         << endl;
    string word4 = "appl";
    cout << "Count Words Starting With " << word4 << " " << T.countwordsstartingwith(word4)
         << endl;
    T.erase(word1);
    cout << "Count Words equal to " << word1 << " " << T.countwordsequaltoo(word1) << endl;
    return 0;
    return 0;
}