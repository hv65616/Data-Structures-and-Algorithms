//CONVERSION USING TRANSFORM ALGORITHM
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str = "abcdefghi";
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    cout << str << endl;
    return 0;
}