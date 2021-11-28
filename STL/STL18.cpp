//STL Inbuilt Algorithm
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

    int a = *min_element(vt.begin(), vt.end());
    cout << a << endl;

    int b = *max_element(vt.begin(), vt.end());
    cout << b << endl;

    int c = accumulate(vt.begin(), vt.end(), 0);
    cout << c << endl;

    int d = count(vt.begin(), vt.end(), 2);
    cout << d << endl;

    auto it = find(vt.begin(), vt.end(), 6);
    if (it != vt.end())
    {
        cout << *it << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    reverse(vt.begin(), vt.end());
    for (int i = 0; i < n; i++)
    {
        cout << vt[i] << " ";
    }
    cout << endl;
    return 0;
}