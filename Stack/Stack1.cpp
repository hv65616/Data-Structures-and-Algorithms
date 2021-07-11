//Introduction to Stack Data Structure
//How to create a stack and its member function like :-
//To push the element
//To pop the element
//To get top value and to check whether stack is empty or not
//Here our dynamic array size is alredy define
#include <iostream>
using namespace std;
#define n 100
class Stack
{
    int *arr;
    int top;

    public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int val)
    {
        if (top == n)
        {
            cout << "Stack Overflow" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void pop()
    {
        if (top == -1)
        {
            cout << "Stack Empty No Element To Pop" << endl;
            return;
        }
        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            cout << "No Element to Show" << endl;
            return 0;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};
int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();
    cout << st.empty() << endl;
    return 0;
}