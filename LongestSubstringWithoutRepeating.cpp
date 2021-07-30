/*
    Finding out the maximun length of substring without repeating its character
    We will take two variable one will store the location i.e index of character and other will store the previous location of character if it appeared previous in string and then out new substring will start from this point
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cin >> str;
    int maxLen = 0;
    int start = -1;
    vector<int> arr(256, -1);
    for (int i = 0; i < str.length(); i++)
    {
        if (arr[str[i]] > start)
        {
            start = arr[str[i]];
        }
        arr[str[i]] = i;
        maxLen = max(maxLen, i - start);
    }
    cout << maxLen << endl;
    return 0;
}