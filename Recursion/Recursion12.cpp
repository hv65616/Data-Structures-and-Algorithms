//COUNTING PATHS IN MAZE
#include<bits/stdc++.h>
using namespace std;
int checkboard(int n,int i,int j)
{
    if(i==n-1 && j==n-1)
    {
        return 1;
    }
    if(i>=n || j>=n)
    {
        return 0;
    }
    return checkboard(n,i+1,j);+checkboard(n,i,j+1);
}
int main()
{
    cout<<checkboard(3,0,0);
    return 0;
}
   