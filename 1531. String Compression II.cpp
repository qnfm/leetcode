#include <string>
using namespace std;
class Solution
{
public:
    int getLengthOfOptimalCompression(string s, int k)
    {
        if (k == 0)
            return min(r, encodelen(s));
        for (int i = 0; i < s.size(); i++)
        {
            string cur = s.substr(0, i) + s.substr(i + 1);
            r = min(r, getLengthOfOptimalCompression(cur, k - 1));
        }
        return r;
    }

private:
    int r = INT_MAX;
    int encodelen(string s)
    {
        if (s.size() == 0 || s.size() == 1)
            return s.size();
        int len = 1, extra = s[0] == s[1] ? 1 : 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i - 1] == s[i])
            {
                extra++;
                continue;
            }
            else
            {
                len += extra != 0 ? to_string(extra).size() : 0;
                extra = 0;
                ++len;
            }
        }
        return len + (extra != 0 ? to_string(extra).size() : 0);
    }
};