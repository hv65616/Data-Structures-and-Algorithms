//Reversing the array using one pointer
#include <bits/stdc++.h>
using namespace std;
void rever(vector<int> &vt, int i, int n)
{
    if (i >= n/2)
    {
        return;
    }
    swap(vt[i], vt[n - i - 1]);
    rever(vt, i + 1, n);
}
int main()
{
    vector<int> vt = {1, 2, 3, 4, 5};
    int n = vt.size();
    rever(vt, 0, n);
    for (auto i : vt)
    {
        cout << i << " ";
    }
    return 0;
}