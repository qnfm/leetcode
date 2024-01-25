#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int countSubstrings(string s)
    {
        vector<int> dp(s.size() + 1, 1);
        for (int i = 0; i < s.size(); i++)
        {
            int cur = 0;
            for (int j = i - 1; j >= 0; j--)
            {
                if (check(s.substr(j, i - j + 1)))
                    cur++;
            }
            dp[i + 1] += dp[i] + cur;
        }
        return dp[s.size()] - 1;
    }

private:
    bool check(string s)
    {
        int i = 0, j = s.size() - 1;
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