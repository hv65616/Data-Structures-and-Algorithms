//Sort the array using count sort
#include <iostream>
using namespace std;
void countSort(int arr[], int n)
{
    int k = INT16_MIN;
    for (int i = 0; i < n; i++)
    {
        k = max(k, arr[i]);
    }
    int arr2[k] = {0};
    for (int i = 0; i < k; i++)
    {
        arr2[arr[i]]++;
    }
    for (int i = 1; i < k; i++)
    {
        arr2[i] = arr2[i] + arr2[i - 1];
    }
    int outarr[n];
    for (int i = n - 1; i >= 0; i++)
    {
        outarr[--arr2[arr[i]]] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = outarr[i];
    }
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
    countSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}