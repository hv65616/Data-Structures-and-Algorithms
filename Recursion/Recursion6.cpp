#include<bits/stdc++.h>
using namespace std;
void revreseString(string s)
{
    if(s.length()==0)
    {
        return;
    }
    string ros = s.substr(1);
    revreseString(ros);
    cout<<s[0];
}
int main()
{
    revreseString("Aman");
    return 0;
}