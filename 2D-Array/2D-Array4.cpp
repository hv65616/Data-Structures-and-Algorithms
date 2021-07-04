//MATRIX SEARCH
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    int tar;
    cin >> tar;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int r = 0, c = m - 1;
    bool res = false;
    while (r < n && c >= 0)
    {
        if (arr[r][c] == tar)
        {
            res = true;
            break;
        }
        else if (arr[r][c] > tar)
        {
            c--;
        }
        else
        {
            r++;
        }
    }

    if (res == true)
    {
        cout << "Element found" << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}