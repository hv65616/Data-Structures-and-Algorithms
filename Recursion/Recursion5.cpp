//Finding the last occurence from an array from last
#include <iostream>
using namespace std;
int lastOccur(int arr[], int n, int i, int key)
{
    if(i == n)
    {
        return -1;
    }
    int restarray = lastOccur(arr, n, i + 1, key);
    if (restarray != -1)
    {
        return restarray; 
    }
    if (arr[i] == key)
    {
        return i;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int key;
    cin >> key;
    cout << lastOccur(arr, 5, 0, key);
    return 0;
}