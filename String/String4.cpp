#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string str = "abcdeaabcddes";
    int arr[26];
    for (int i = 0; i < 26; i++)
    {
        arr[i] = 0;
    }
    for (int i = 0; i < str.length(); i++)
    {
        arr[str[i] - 'a']++;
    }
    int maxF = 0;
    char ch = 'a';
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] > maxF)
        {
            maxF = arr[i];
            ch = i + 'a';
        }
    }
    cout << maxF << " " << ch << endl;
    return 0;
}