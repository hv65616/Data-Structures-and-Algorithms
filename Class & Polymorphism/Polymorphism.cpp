#include <iostream>
using namespace std;
class Complex
{
private:
    int real, imag;

public:
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }
    Complex operator+(Complex &a)
    {
        Complex res;
        res.real = real + a.real;
        res.imag = imag + a.imag;
        return res;
    }
    void display()
    {
        cout << real << "+i" << imag << endl;
    }
};
int main()
{
    Complex c1(12, 7), c2(13, 5);
    Complex c3 = c1 + c2;
    c3.display();
    return 0;
}