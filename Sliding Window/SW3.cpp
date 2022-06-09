// Sliding window 3
// Count Occurences Of Anagrams
#include <bits/stdc++.h>
using namespace std;
int countanagrams(string s1, string s2)
{
    int i = 0;
    int j = 0;
    int k = s2.length();
    int ans = 0;
    map<char, int> mp;
    for (int i = 0; i < s2.length(); i++)
    {
        mp[s2[i]]++;
    }
    int count = mp.size();
    while (j < s1.size())
    {
        if (mp.find(s1[j]) != mp.end())
        {
            mp[s1[j]]--;
            if (mp[s1[j]] == 0)
            {
                count--;
            }
        }
        if (j - i + 1 < k)
        {
            j++;
        }
        else if (j - i + 1 == k)
        {
            if(count==0)
            {
                ans++;
            }
            if(mp.find(s1[i])!=mp.end())
            {
                mp[s1[i]]++;
                if(mp[s1[i]]==1)
                {
                    count++;
                }
            }
            i++;
            j++;
        }
    }
    return ans;
}
int main()
{
    string s1 = "aabaabaa";
    string s2 = "aaba";
    int ans = countanagrams(s1, s2);
    cout << ans << " ";
    return 0;
}