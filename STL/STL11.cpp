//https : //www.hackerrank.com/challenges/cpp-maps/problem?isFullScreen=true
#include <bits/stdc++.h>
        using namespace std;
int main()
{
    map<string, int> mp;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int query_type, x;
        string st;
        cin >> query_type >> st;
        if (query_type == 1)
        {
            cin >> x;
            mp[st] += x;
        }
        else if (query_type == 2)
        {
            mp.erase(st);
        }
        else
        {
            if (mp.find(st) != mp.end())
            {
                cout << mp[st] << endl;
            }
            else
            {
                cout << "0" << endl;
            }
        }
    }
    return 0;
}