//THROUGH RECURSION PRINTING ELEMENTS IN INCREASING ORDER
#include<iostream>
using namespace std;
void increasingOrder(int n)
{
    if(n==0)
    {
        return;
    }
    increasingOrder(n-1);
    cout<<n<<endl;
}
int main()
{
    int n;
    cin>>n;
    increasingOrder(n);
    return 0;
}