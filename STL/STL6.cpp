//For the given N store the N string and after that for the queries Q print their occurences
#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> ump;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ump[s]++;
    }
    int q;
    cin >> q;
    while (--q)
    {
        string str;
        cin >> str;
        cout << ump[str] << endl;
    }
    return 0;
}