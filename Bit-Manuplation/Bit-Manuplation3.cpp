//USING BIT FIND NUMBER OF 1 IN THE NUMBER
#include <iostream>
using namespace std;

int numberOfOnes(int n)
{
    int count = 0;
    while (n)
    {
        n = n & n - 1;
        count++;
    }
    return count;
}

int main()
{
    cout << numberOfOnes(19) << endl;
    return 0;
}