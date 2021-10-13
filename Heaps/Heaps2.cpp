//Heaps STL
//Where for max heap we use priority_queue<int, vector<int>>
//And fro min heap we use priority_queue<int, vector<int>, greater<int>>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int>> mx;
    mx.push(1);
    mx.push(3);
    mx.push(2);
    mx.push(5);
    mx.push(4);
    cout << mx.top() << endl;
    mx.pop();
    cout << mx.top() << endl;

    priority_queue<int, vector<int>, greater<int>> min;
    min.push(1);
    min.push(2);
    min.push(3);
    min.push(4);
    min.push(5);
    cout << min.top() << endl;
    min.pop();
    cout << min.top() << endl;
    return 0;
}