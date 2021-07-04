#include <bits/stdc++.h>
using namespace std;
bool mycompare(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first < p2.first;
}
int main()
{
    int arr[] = {3, 4, 1, 5, 2};
    vector<pair<int, int>> p;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[i]); i++)
    {
        p.push_back(make_pair(arr[i], i));
    }
    sort(p.begin(), p.end(), mycompare);
    for (int i = 0; i < p.size(); i++)
    {
        arr[p[i].second] = i;
    }
    for (int i = 0; i < p.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}