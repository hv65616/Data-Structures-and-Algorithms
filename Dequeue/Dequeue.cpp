/*
    Dequeue is a combination of queue and stack
    We can push element from starting and from ending
    We can pop element from starting and from ending
*/
#include <iostream>
#include <deque>
using namespace std;
int main()
{
    deque<int> d1;
    d1.push_back(1);
    d1.push_back(2);
    d1.push_front(3);
    d1.push_front(4);
    for (auto i : d1)
    {
        cout << i << " ";
    }
    cout<<endl;
    d1.pop_back();
    d1.pop_front();
    for (auto i : d1)
    {
        cout << i << " ";
    }
    return 0;
}