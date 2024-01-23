// Runtime 2213ms Memory 499.20 MB
/*
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        for (auto &s : arr)
        {
            unordered_set<char> st;
            for (auto c : s)
            {
                if (!st.contains(c))
                    st.insert(c);
                else
                {
                    s = "";
                    break;
                }
            }
        }
        unordered_set<char> cur;
        dfs(arr, 0, cur);
        return r;
    }

private:
    int r = 0;
    void dfs(const vector<string> &s, int idx, unordered_set<char> cur)
    {
        if (idx >= s.size())
        {
            r = max(r, (int)cur.size());
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            int j = 0;
            while (j < s[i].size() && !cur.contains(s[i][j]))
                j++;
            if (j == (int)s[i].size())
            {
                cur.insert(s[i].begin(), s[i].end());
                dfs(s, i + 1, cur);
                for (auto c : s[i])
                    cur.erase(c);
            }
            else
                dfs(s, i + 1, cur);
        }
    }
};
*/

// Runtime 14ms Memory 9.62 MB
#include <bit>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    int maxLength(vector<string> &arr)
    {
        int cur = 0;
        dfs(arr, 0, cur);
        return r;
    }

private:
    int r = 0;
    void dfs(const vector<string> &s, int idx, int cur)
    {
        if (idx >= s.size())
        {
            r = max(r, popcount((unsigned int)cur));
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            int j = 0, charBitSet = 0;
            for (auto c : s[i])
            {
                int mask = 1 << (c - 'a');
                if ((charBitSet & mask) != 0 || (cur & mask) != 0)
                    break;
                j++;
                charBitSet ^= mask;
            }
            if (j == (int)s[i].size())
            {
                cur ^= charBitSet;
                dfs(s, i + 1, cur);
                cur ^= charBitSet;
            }
            else
                dfs(s, i + 1, cur);
        }
    }
};