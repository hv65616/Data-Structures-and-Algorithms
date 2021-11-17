//Print the string with its repetation
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        mp[str]++;
    }
    for (auto it : mp)
    {
        cout << it.first << "->" << it.second << endl;
    }
    return 0;
}