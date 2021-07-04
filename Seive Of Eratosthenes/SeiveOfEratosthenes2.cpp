#include<iostream>
using namespace std;
void primeFactorization(int n)
{
    int arr[n] = {0};
    for(int i=2;i<=n;i++)
    {
        arr[i] = i;
    }
    for(int i=2;i<=n;i++)
    {
        if(arr[i]==i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(arr[j]==j)
                {
                    arr[j] = i;
                }
            }
        }
    }
    while(n!=1)
    {
        cout<<arr[n]<<" ";
        n=n/arr[n];
    }
}

int main()
{
    int n;
    cin>>n;
    primeFactorization(n);
    return 0;
}