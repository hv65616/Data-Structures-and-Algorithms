//https : //www.hackerrank.com/challenges/cpp-sets/problem?fbclid=IwAR1Z1fv5RnGAqByvADCRUv4pYQAAmQ_zV5rgVVCagY-DneWu6TSWENdncsY&isFullScreen=true
#include <bits/stdc++.h>
        using namespace std;
int main()
{
    set<int> st;
    int q;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int type_query, x;
        cin >> type_query;
        cin >> x;
        if (type_query == 1)
        {

            st.insert(x);
        }
        else if (type_query == 2)
        {
            st.erase(x);
        }
        else
        {
            if (st.find(x) == st.end())
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}