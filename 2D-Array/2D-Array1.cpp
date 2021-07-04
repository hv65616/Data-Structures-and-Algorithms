//PRINT THE ELEMENTS OF A MATRIX IN SPIRAL ORDER TRANSVERSAL
#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int row_start = 0;
    int row_end = n - 1;
    int column_start = 0;
    int column_end = n - 1;
    while (row_start <= row_end && column_start <= column_end)
    {
        for (int i = column_start; i <= column_end; i++)
        {
            cout << arr[row_start][i] << " ";
        }
        row_start++;
        for (int j = row_start; j <= row_end; j++)
        {
            cout << arr[j][column_end] << " ";
        }
        column_end--;
        for (int k = column_end; k >= column_start; k--)
        {
            cout << arr[row_end][k] << " ";
        }
        row_end--;
        for (int l = row_end; l >= row_start; l--)
        {
            cout << arr[l][column_start] << " ";
        }
        column_start++;
    }
    return 0;
}