/*
    StackSpan Problem
    In the problem we have to find the days on which the price is low as compare to the current day
    We will make pair of stack the pair consist of price and day
    Now when a pair is push we will check whether the price at top is is low then the current price then we will increment the day by 1 and push that into pair
    After that we will push the whole pair into stack
    And correspondinly we will push the day into a vector array
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> stockspan(vector<int> prices)
{
    vector<int> output;
    stack<pair<int, int>> st;
    for (auto price : prices)
    {
        int days = 1;
        while (!st.empty() && st.top().first <= price)
        {
            days += st.top().second;
            st.pop();
        }
        st.push(make_pair(price, days));
        output.push_back(days);
    }
    return output;
}
int main()
{
    vector<int> prices = {100, 80, 60, 70, 70, 75, 85};
    vector<int> days = stockspan(prices);
    for (auto i : days)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}