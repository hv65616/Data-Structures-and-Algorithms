/*
    Stack Using Queue
    Making pop() function main and important
    Initially taking 2 empty queue q1 and q2 and start inserting element in q1
    After inserting we pop out the element from starting till one last element left and all the poped out element will get store into other queue
    The last element left will also get poped out and then we swap the queue initially back and the process goes on
    But if we want top element then first we store that last element of q1 into a variable then inserting into q2 and then remove it
*/
#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    int N;
    queue<int> q1;
    queue<int> q2;

public:
    Stack()
    {
        N = 0;
    }
    void push(int val)
    {
        q1.push(val);
        N++;
    }
    void pop()
    {
        if (q1.empty())
        {
            return;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        N--;
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }
    int top()
    {
        if (q1.empty())
        {
            return -1;
        }
        while (q1.size() != 1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        int last = q1.front();
        q2.push(last);
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;

        return last;
    }

    int size()
    {
        return N;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.size() << endl;
    return 0;
}