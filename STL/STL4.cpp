//Introduction To Maps
#include <bits/stdc++.h>
using namespace std;
int main()
{
    map<int, string> mp; //Declaration Of Maps
    mp[1] = "abc"; //Inserting key and value of map key = int and value = string
    mp[4] = "jkl";
    mp[2] = "def";
    mp.insert({3, "ghi"}); // Another way of inserting key and value

    map<int, string>::iterator it; //Initializing of iterator
    cout << "Way-1 For Iteration" << endl;
    for (it = mp.begin(); it != mp.end(); it++)
    {
        cout << (*it).first << "->" << (*it).second << endl;
    }

    cout << "Way-2 For Iteration" << endl;
    for (auto value = mp.begin(); value != mp.end(); value++)
    {
        cout << (*value).first << "->" << (*value).second << endl;
    }

    cout << "Way-3 For Iteration" << endl;
    for (auto &value : mp)
    {
        cout << value.first << "->" << value.second << endl;
    }

    auto it1 = mp.find(3); //O(log(n))
    if (it1 == mp.end())
    {
        cout << "No Value" << endl;
    }
    else
    {
        cout << (*it1).first << " " << (*it1).second << endl;
    }
    mp.erase(3); //O(log(n))
    for (auto &value : mp)
    {
        cout << value.first << "->" << value.second << endl;
    }
    return 0;
}