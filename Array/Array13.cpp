//FINDING OUT THE MAXIMUM SUM OF SUBARRAY
//DONE THROUGH KADANES THEOREM
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
    int currSum = 0;
    int maxSum = INT16_MIN;
    for(int i=0;i<n;i++)
    {
        currSum+=arr[i];
        if(currSum<0)
        {
            currSum = 0;
        }
        maxSum = max(currSum,maxSum);
    }
    cout<<maxSum<<endl;
    return 0;
}