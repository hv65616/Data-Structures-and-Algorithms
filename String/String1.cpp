//CONVERSION OF CHARACTER FROM LOWER TO UPPER AND UPPER TO LOWER
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str = "abcdef";
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] - 32;
    }
    cout << str << endl;
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = str[i] + 32;
    }
    cout << str << endl;
    return 0;
}