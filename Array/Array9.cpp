//TO FIND OUT THE REPETITION OF A NUMBER WITH THE NUMBER SHOULD PRESENT ON SMALLEST INDEX
//ASKED IN AMAZON GOOGLE
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    const int N = 10e6 + 2;
    int ARR[N];
    for (int i = 0; i < N; i++)
    {
        ARR[i] = -1;
    }
    int mindx = INT16_MAX;
    for (int i = 0; i < n; i++)
    {
        if (ARR[arr[i]] != -1)
        {
            mindx = min(mindx, ARR[arr[i]]);
        }
        else
        {
            ARR[arr[i]] = i;
        }
    }
    if (mindx == INT16_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << mindx + 1 << endl;
    }
    return 0;
}