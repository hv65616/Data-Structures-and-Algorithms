#include<bits/stdc++.h>
using namespace std;
string printXAtLast(string s)
{
    if(s.length()==0)
    {
        return "";
    }
    char ch = s[0];
    string ans = printXAtLast(s.substr(1));
    if(ch == 'x')
    {
        return ans+ch;
    }
    return ch+ans;
}
int main()
{
    cout<<printXAtLast("axbxcxd");
    return 0;
}