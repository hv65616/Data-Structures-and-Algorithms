//Quick Sort(Divide And Conquere)
#include<iostream>
using namespace std;
void swap(int arr[],int i,int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[],int l,int r)
{
    int element = arr[r];
    int i = l-1;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<element)
        {
            i++;
            swap(arr,i,j);
        }
    }
    swap(arr,i+1,r);
    return i+1;
}

void quickSort(int arr[],int l,int r)
{
    if(l<r)
    {
        int p = partition(arr, l, r);
        quickSort(arr, l, p-1);
        quickSort(arr, p + 1, r);
    }
}
int main()
{
    int arr[] = {5,4,3,2,1};
    quickSort(arr,0,4);
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}