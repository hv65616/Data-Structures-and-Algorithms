//Iterators
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vt = {1, 2, 3, 4, 5, 6};
    vector<int>::iterator it; //Declaration  of iterator of vector type
    for (it = vt.begin(); it != vt.end(); it++)
    {
        cout << *it << " "; //Printing of values 
    }
    cout << endl;
    vector<pair<int, int>> vp = {{1, 2}, {3, 4}, {5, 6}};
    vector<pair<int, int>>::iterator it_vp; //Declaration of iterator of vector pair type
    for (it_vp = vp.begin(); it_vp != vp.end(); it_vp++)
    {
        cout << (*it_vp).first << " " << (*it_vp).second << endl; //Printing of first and second value of pair stored in vector
    }
    return 0;
}