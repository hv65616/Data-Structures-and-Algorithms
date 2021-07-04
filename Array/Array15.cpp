//TO FIND OUT THE PAIR SUM OF A GIVEN ARRAY
#include<iostream>
using namespace std;
bool pairSum(int arr[],int n,int k)
{
    int i = 0;
    int j = n-1;
    while(i<=j)
    {
        if(arr[i]+arr[j]==k)
        {
            cout<<i<<" "<<j<<endl;
            return true;
        }
        else if(arr[i]+arr[j]<k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

int main()
{
    int n;
    cin>>n;
    int k;
    cin>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<pairSum(arr,n,k)<<endl;
    return 0;
}