//Question - Given the marks and name of N students we have to print the marks and name in descending order of marks if two or more students have same marks then print the marks and name in lexographically order.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, multiset<string>> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        int marks;
        cin >> str >> marks;
        mp[marks].insert(str);
    }
    auto last_it = --mp.end();
    while (true)
    {
        auto &students = (*last_it).second;
        int marks = (*last_it).first;
        for (auto student : students)
        {
            cout << student << " " << marks << endl;
        }
        if (last_it == mp.begin())
        {
            break;
        }
        last_it--;
    }
    return 0;
}