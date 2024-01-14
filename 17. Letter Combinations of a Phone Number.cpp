#include <array>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        if (digits.empty())
            return {};
        vector<string> r;
        string cur;
        dfs(digits, r, 0, cur);
        return r;
    }

private:
    const array<string, 8> map{"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(const string &s, vector<string> &r, int idx, string &cur)
    {
        if (idx == s.size())
        {
            r.push_back(cur);
            return;
        }
        string tmp = map[s[idx] - '2'];

        for (int i = 0; i < tmp.size(); i++)
        {
            cur.push_back(tmp[i]);
            dfs(s, r, idx + 1, cur);
            cur.pop_back();
        }
    }
};