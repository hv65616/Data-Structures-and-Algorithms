#include <bits/stdc++.h>
using namespace std;
bool ispositive(int x)
{
    return x > 0;
}
int main()
{
    vector<int> v = {-2, 1, 3};

    cout << all_of(v.begin(), v.end(), [](int x)
                   { return x > 0; })
         << endl;

    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x > 0; })
         << endl;

    cout << none_of(v.begin(), v.end(), [](int x)
                    { return x > 0; })
         << endl;

    cout << any_of(v.begin(), v.end(), [](int x)
                   { return x % 2 == 0; })
         << endl;

    return 0;
}