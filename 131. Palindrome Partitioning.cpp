#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> r;
        vector<string> cur;
        dfs(s, r, 0, cur);
        return r;
    }

private:
    bool check(string &s)
    {
        int lo = 0, hi = s.size() - 1;
        while (lo <= hi)
        {
            if (s[lo++] != s[hi--])
                return false;
        }
        return true;
    }
    void dfs(const string &s, vector<vector<string>> &r, int idx, vector<string> cur)
    {
        if (idx == s.size())
        {
            r.push_back(cur);
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            string t = s.substr(idx, i - idx + 1);
            if (!check(t))
                continue;
            cur.push_back(t);
            dfs(s, r, i + 1, cur);
            cur.pop_back();
        }
    }
};