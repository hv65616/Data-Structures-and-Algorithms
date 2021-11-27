//lower_bound and upper_bound
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vt(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vt[i];
    }
    sort(vt.begin(), vt.end());
    for (int i = 0; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    cout << endl;
    auto it = lower_bound(vt.begin(), vt.end(), 7);
    if (it == vt.end())
    {
        cout << "Not Found";
    }
    cout << (*it) << endl;
    auto it2 = upper_bound(vt.begin(), vt.end(), 5);
    cout << (*it2) << endl; 
    return 0;
}