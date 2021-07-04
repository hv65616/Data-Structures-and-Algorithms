//FINDING THE PERMUTATION OF WORD
#include<iostream>
using namespace std;
void permuOfWord(string s,string ans)
{
    if(s.length() == 0)
    {
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<s.length();i++)
    {
        char ch = s[0];
        string ros = s.substr(i,1)+s.substr(i+1);
        permuOfWord(ros,ch+ans);
    }
}
int main()
{
    permuOfWord("ABC"," ");
    return 0;
}