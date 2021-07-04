//THROUGH RECURSION FINDING WEATHER ARRRAY IS SORTED OR NOT
#include<iostream>
using namespace std;
bool sorted(int arr[],int n)
{
    if(n==1)
    {
        return true;
    }
    bool furthurChek = sorted(arr+1,n-1);
    return (arr[0]<arr[1] && furthurChek);
}
int main()
{
    int arr[] = {1,2,3,4,5};
    cout<<sorted(arr,5);
    return 0;
}