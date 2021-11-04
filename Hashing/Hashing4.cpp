//Check whether the given array consist any subarray whose sum is equal to zero
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    vector<int> vt;
    vt.push_back(1);
    vt.push_back(-1);
    vt.push_back(1);
    vt.push_back(-1);

    int len = vt.size();

    unordered_map<int, bool> ump;

    int sum = 0;

    bool ans = false;

    for (int i = 0; i < len; i++)
    {
        sum += vt[i];
        if (sum == 0 || ump[sum] == true)
        {
            ans = true;
            break;
        }
    }

    if (ans)
    {
        cout << "Subarray wiht sum zero is present" << endl;
    }
    else
    {
        cout << "Subarrays with sum zero is not present" << endl;
    }
    return 0;
}