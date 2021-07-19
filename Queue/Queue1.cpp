/* 
    Queue follows the FIFO i.e first in first out
    Here we create our own class of Queue to perfrom queue operation accordingly
    enQueue = push , deQueue = pop , peek = top , empty is empty
    We take two pointer front and back and initially put them in -1 as the element get added on front remain in first element while back moves
*/
#include <iostream>
using namespace std;
#define n 50
class Queue
{
    int *arr;
    int front;
    int back;

public:
    Queue()
    {
        arr = new int[n];
        front = -1;
        back = -1;
    }

    void enQueue(int val)
    {
        if (back == n - 1)
        {
            cout << "Queue Overflow" << endl;
            return;
        }
        back++;
        arr[back] = val;
        if (front == -1)
        {
            front++;
        }
    }

    void deQueue()
    {
        if (front == -1 || front > back)
        {
            cout << "No Elements To Be Popped" << endl;
            return;
        }
        front++;
    }

    int peek()
    {
        if (front == -1 || front > back)
        {
            cout << "No Element To Be Shown" << endl;
            return -1;
        }
        return arr[front];
    }

    bool empty()
    {
        if (front == -1 || front > back)
        {
            cout << "Queue is alredy empty" << endl;
            return true;
        }
        return false;
    }
};
int main()
{
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    cout << q.peek() << endl;
    q.deQueue();
    cout << q.peek() << endl;
    q.deQueue();
    cout << q.peek() << endl;
    q.deQueue();
    cout << q.peek() << endl;
    q.deQueue();
    cout << q.empty() << endl;
    return 0;
}