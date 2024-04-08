/*
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool wordBreak(const string s, vector<string> &wordDict)
    {
        str = s;
        n = s.size();
        memo = vector<int>(n, 0);
        return dfs(wordDict, 0) == 1;
    }

private:
    int n;
    vector<int> memo;
    string str;
    int dfs(vector<string> &word, int idx)
    {
        if (idx == n)
            return 1;
        if (memo[idx] != 0)
            return memo[idx];
        int r = -1;
        for (auto &w : word)
        {
            if (r == 1)
                break;
            if (w.size() + idx <= n)
            {
                int i = idx;
                while (str[i] == w[i - idx] && i < w.size() + idx)
                    i++;
                if (i == w.size() + idx)
                    r = dfs(word, i) == 1;
            }
        }
        return memo[idx] = (r == 1 ? 1 : -1);
    }
};
*/
#include <string>
#include <vector>
#include <bitset>
using namespace std;
class Solution
{
public:
    bool wordBreak(const string s, vector<string> &wordDict)
    {
        const int n = s.size();
        bitset<301> dp;
        str = s;
        dp[n] = true;
        for (int i = n - 1; i >= 0; i--)
        {
            for (auto &w : wordDict)
            {
                if (check(w, i))
                    dp[i] = dp[i + w.size()];
                if (dp[i])
                    break;
            }
        }
        return dp[0];
    }

private:
    string str;
    bool check(string w, int i)
    {
        int j = i + w.size() - 1;
        if (j >= str.size())
            return false;
        int s;
        for (s = i; str[s] == w[s - i] && s <= j; s++)
        {
        }
        return s == j + 1;
    }
};