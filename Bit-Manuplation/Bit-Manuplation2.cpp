//USING BIT FINDING THE NUMBER IS POWER OF 2 OR NOT
#include <iostream>
using namespace std;
int powerof(int n)
{
    return (n && !(n & n - 1));
}
int main()
{
    cout << powerof(16) << endl;
    return 0;
}