//IN THIS WE SORT OUR NUMBERS TO MAKE A LARGEST NUMBER FROM GIVEN NUMBERS
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
    string str = "5469987";
    sort(str.begin(),str.end(),greater<int>());
    cout<<str<<endl;
    return 0;
}