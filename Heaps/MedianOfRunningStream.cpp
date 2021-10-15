// Question Based On Heap Application
// Medium Of Running Stream
// In this we have to find the median as the element get added into the heap and that we did by dividing the heap into two part one is minheap and second is max heap
#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>> mxheap;
priority_queue<int, vector<int>, greater<int>> minheap;

void insert(int val)
{
    if (mxheap.size() == minheap.size())
    {
        if (mxheap.size() == 0)
        {
            mxheap.push(val);
            return;
        }
        if (val < mxheap.top())
        {
            mxheap.push(val);
        }
        else
        {
            minheap.push(val);
        }
    }
    else
    {
        if (mxheap.size() > minheap.size())
        {
            if (val >= mxheap.top())
            {
                minheap.push(val);
            }
            else
            {
                int temp = mxheap.top();
                mxheap.pop();
                minheap.push(temp);
                mxheap.push(val);
            }
        }
        else
        {
            if (val <= minheap.top())
            {
                mxheap.push(val);
            }
            else
            {
                int temp = minheap.top();
                minheap.pop();
                mxheap.push(temp);
                minheap.push(val);
            }
        }
    }
}

double findMedian()
{
    if (mxheap.size() == minheap.size())
    {
        return (mxheap.top() + minheap.top()) / 2.0;
    }
    else if (mxheap.size() > minheap.size())
    {
        return mxheap.top();
    }
    else
    {
        return minheap.top();
    }
}
int main()
{
    insert(10);
    cout << findMedian() << endl;
    insert(15);
    cout << findMedian() << endl;
    insert(21);
    cout << findMedian() << endl;
    insert(30);
    cout << findMedian() << endl;
    insert(18);
    cout << findMedian() << endl;
    insert(19);
    cout << findMedian() << endl;
    return 0;
}