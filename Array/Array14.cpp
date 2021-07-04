//MAXIMUN SUB OF CIRCULAR SUBARRAY
//DONE THROUGH USING KADANES THEOREM
#include <iostream>
#include <climits>
using namespace std;

int kadane(int arr[], int n)
{
    int currSum = 0;
    int mx = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        currSum += arr[i];
        if (currSum < 0)
        {

            currSum = 0;
        }
        mx = max(currSum, mx);
    }
    return mx;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int wrapsum;
    int nonwrapsum;
    int mx = INT16_MIN;
    nonwrapsum = kadane(arr, n);
    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }
    wrapsum = totalsum + kadane(arr, n);
    mx = max(wrapsum, nonwrapsum);
    cout << mx << endl;
    return 0;
}