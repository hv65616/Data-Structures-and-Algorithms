//Number of ways available to pair or not to pair n number of friends
#include<iostream>
using namespace std;
int pairingFriends(int n)
{
    if(n==0 || n==1 || n==2)
    {
        return n;
    }
    return pairingFriends(n-2)+pairingFriends(n-1)*2;
}
int main()
{
    cout<<pairingFriends(4)<<endl;
    return 0;
}