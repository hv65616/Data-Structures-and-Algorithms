//Nesting In STL Maps And Sets  
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<pair<string, string>, vector<int>> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string st1, st2;
        cin >> st1 >> st2;
        int num;
        cin >> num;
        for (int j = 0; j < num; j++)
        {
            int x;
            cin >> x;
            mp[{st1, st2}].push_back(x);
        }
    }

    for (auto &it : mp)
    {
        auto &full = it.first;
        auto &list = it.second;
        cout << full.first << " " << full.second << " " << endl;
        cout << list.size() << endl;
        for (auto &it2 : list)
        {
            cout << it2 << " ";
        }
        cout << endl;
    }
    return 0;
}