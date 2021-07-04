//Finding the first occurence from an array from the starting
#include <iostream>
using namespace std;
int firstOccr(int arr[], int n, int i, int key)
{
    if (i == n)
    {
        return -1;
    }
    if (arr[i] == key)
    {
        return i;
    }
    return firstOccr(arr, n, i + 1, key);
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key;
    cin >> key;
    cout << firstOccr(arr, 5, 0, key);
    return 0;
}