/*
    Linked List Implementation Using Queue
    Creating two class one for creating node and other for functionality of Queue
    Here, we do not create array instead we create Linked List and perform all the operation on Linked List
*/
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void enQueue(int val)
    {
        Node *n = new Node(val);
        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }
        back->next = n;
        back = n;
    }

    void deQueue()
    {
        if (front == NULL)
        {
            cout << "Queue not have element to pop" << endl;
            return;
        }
        Node *todelete = front;
        front = front->next;
        delete todelete;
    }

    int peek()
    {
        if (front == NULL)
        {
            cout << "Queue does not have element to show" << endl;
            return -1;
        }
        return front->data;
    }

    bool empty()
    {
        if (front == NULL)
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