//Sliding Window
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vt;
    vt.push_back(-2);
    vt.push_back(10);
    vt.push_back(1);
    vt.push_back(3);
    vt.push_back(2);
    vt.push_back(-1);
    vt.push_back(4);
    vt.push_back(5);
    int len = vt.size();
    int k;
    cout << "Enter the size of window: ";
    cin >> k;
    int mini = INT16_MAX;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += vt[i];
    }
    mini = min(mini, sum);
    for (int i = 1; i <= len - k + 1; i++)
    {
        sum -= vt[i - 1];
        sum += vt[i + k - 1];
        mini = min(mini, sum);
    }
    cout << mini << endl;
    return 0;
}