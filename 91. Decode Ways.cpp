#include <string>
#include <unordered_map>
using namespace std;
// recursive
/*
class Solution
{
public:
    int numDecodings(string s)
    {
        return helper(s);
    }

private:
    unordered_map<int, int> memo;
    int helper(string s, int idx = 0)
    {
        if (memo.contains(idx))
            return memo[idx];
        if (idx == s.size())
            return 1;
        if (s[idx] == '0')
            return 0;
        if (idx == s.size() - 1)
            return 1;
        int ans = helper(s, idx + 1);
        if (stoi(s.substr(idx, 2)) <= 26)
            ans += helper(s, idx + 2);
        memo[idx] = ans;
        return ans;
    }
};
*/

// dp
class Solution
{
public:
    int numDecodings(string s)
    {
        if (s[0] == '0')
            return 0;
        int dp0, dp1 = (*s.rbegin()) == '0' ? 0 : 1, dp2 = 1;
        int i = s.size() - 2;
        while (i >= 0)
        {
            if (s[i] == '0')
                dp0 = 0;
            else
            {
                dp0 = dp1;
                if (s[i] == '1' || (s[i] == '2' && s[i + 1] >= '0' && s[i + 1] <= '6'))
                    dp0 += dp2;
            }
            dp2 = dp1, dp1 = dp0, dp0 = 0;
            i--;
        }
        return dp1;
    }
};