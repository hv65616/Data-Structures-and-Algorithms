//Comparator Function
//Using A Comparator Function We Will Sort The Pair
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
    {
        if (a.first > b.first)
        {
            return false;
        }
        return true;
    }
    else
    {
        if (a.second < b.second)
        {
            return false;
        }
        return true;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vp(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vp[i].first >> vp[i].second;
    }
    sort(vp.begin(), vp.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }
    return 0;
}