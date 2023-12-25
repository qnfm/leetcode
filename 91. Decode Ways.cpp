#include <string>
#include <unordered_map>
using namespace std;
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