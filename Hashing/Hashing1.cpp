//Find the frequency of repeating elements using hashing
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    //Initializing a map function which will use to map the values with its frequency
    map<int, int> mp;

    //Store the key with its value
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    //Creating of map function iterator
    map<int, int>::iterator it;

    //Used to iterate the map
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }

    return 0;
}