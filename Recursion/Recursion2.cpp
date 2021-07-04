//THROUGH RECURSION PRINTING ELEMENTS IN DECREASING ORDER
#include<iostream>
using namespace std;
void decreasingOrder(int n)
{
    if(n==0)
    {
        return;
    }
    cout<<n<<endl;
    decreasingOrder(n-1);
}
int main()
{
    int n;
    cin>>n;
    decreasingOrder(n);
    return 0;
}