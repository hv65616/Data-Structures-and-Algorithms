#include<iostream>
using namespace std;
class base
{
    public:
    virtual void print()
    {
        cout<<"Base class print func"<<endl;
    }
    virtual void display()
    {
        cout<<"Base class derived func"<<endl;
    }
};
class derived : public base
{
    public:
    void print()
    {
        cout<<"Derived class print func"<<endl;
    }
    void display()
    {
        cout<<"Derived class display func"<<endl;
    }
};
int main()
{   
    base *baseptr;
    derived der;
    baseptr = &der;
    baseptr->display();
    baseptr->print();
    return 0;
}