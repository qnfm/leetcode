#include <vector>
#include <string>
using namespace std;
// Runtime 481ms Memory 461.06MB
/*
class Solution
{
public:
    int countSubstrings(string s)
    {
        this->s = s;
        vector<int> dp(s.size() + 1, 1);
        for (int i = 0; i < s.size(); i++)
        {
            int cur = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                string tmp = s.substr(j, i - j + 1);
                if (check(j, i))
                    cur++;
            }
            dp[i + 1] += dp[i] + cur;
        }
        return dp[s.size()] - 1;
    }

private:
    string s;
    bool check(int i, int j)
    {
        while (i <= j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
*/
class Solution
{
public:
    int countSubstrings(string s)
    {
        int r = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int left = i, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
                r++;
            }
            left = i - 1, right = i;
            while (left >= 0 && right < s.size() && s[left] == s[right])
            {
                left--;
                right++;
                r++;
            }
        }
        return r;
    }
};