//FIND THE MAXIMUM ELEMENT IN ARRAY
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int mx = INT16_MIN;;
    for(int i=0;i<n;i++)
    {
        mx = max(mx,arr[i]);
        cout<<mx<<endl;
    }
    return 0;
}