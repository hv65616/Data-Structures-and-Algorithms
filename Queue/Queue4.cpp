/*
    Stack Using Queue
    Implement the stack using the property and functionality of queue
    Initially we will be having 2 empty queue
    First we will push element into queue q2 and then push every element of q1 into q2 then move all elements of q2 into q1 
    And the process goes on
    Here we will be making push() our heavy function 
*/
#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q1;
    queue<int> q2;
    int N;

public:
    Stack()
    {
        N = 0;
    }
    void push(int val)
    {
        q2.push(val);
        N++;
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp;
        temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop()
    {
        q1.pop();
        N--;
    }

    int top()
    {
        return q1.front();
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
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.size() << endl;
    return 0;
}