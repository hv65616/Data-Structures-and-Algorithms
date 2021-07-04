//Encapsulation in Class
#include <iostream>
using namespace std;
class A
{
private:
    int a;
    void disA()
    {
        cout << "Private A\n";
    }

protected:
    int b;
    void disB()
    {
        cout << "Protected B\n";
    }

public:
    int c;
    void disC()
    {
        cout << "Public C\n";
    }
};
int main()
{
    A obj;
    obj.disC();
    return 0;
}