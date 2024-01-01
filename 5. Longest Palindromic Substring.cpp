/*
https://leetcode.com/problems/palindrome-permutation/description/
https://leetcode.com/problems/maximize-palindrome-length-from-subsequences/
https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/
https://leetcode.com/problems/largest-palindromic-number/description/
*/
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int sz = s.size();
        vector<vector<bool>> dp(sz, vector<bool>(sz));
        pair<int, int> r{0, 0};
        for (int i = 0; i < sz; i++)
        {
            dp[i][i] = true;
            if (i < sz - 1 && s[i] == s[i + 1])
            {
                dp[i][i + 1] = true;
                r = {i, i + 1};
            }
        }

        for (int diff = 2; diff < sz; diff++)
        {
            for (int i = 0; i < sz - diff; i++)
            {
                int j = i + diff;
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                    r = {i, j};
                }
            }
        }
        return s.substr(r.first, r.second - r.first + 1);
    }
};