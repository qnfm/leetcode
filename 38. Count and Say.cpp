#include <string>
using namespace std;
class Solution
{
public:
    string countAndSay(int n)
    {
        if (n < 1)
            return "-1";
        if (n == 1)
            return "1";
        string r = "1";
        for (int i = 1; i < n; i++)
        {
            r = build(r);
        }
        return r;
    }
    string build(string s)
    {
        string r;
        int i = 0;
        while (i < s.size())
        {
            int count = 0;
            char cur = s[i];
            while (i < s.size() && s[i] == cur)
            {
                ++i;
                count++;
            }
            r += to_string(count) + cur;
        }
        return r;
    }
};