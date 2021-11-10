#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    vector<int> arr;
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int size = mp.size();
        if (mp[arr[i]] == 0 && size == k)
        {
            break;
        }
        mp[arr[i]]++;
    }

    vector<int> ans;
    map<int, int>::iterator it;
    for (it = mp.begin(); it != mp.end(); it++) g
    {
        if (it->second != 0)
        {
            pair<int, int> pp;
            pp.first = it->second;
            pp.second = it->first;
            ans.push_back(pp);
        }
    }

    sort(ans.begin(), ans.end(), greater<pair<int, int>>());

    vector<int>::iterator it2;

    for (it2 = ans.begin(); it2 != ans.end(); it2++)
    {
        cout << it2->second << " " << it2->first << endl;
    }
    return 0;
}