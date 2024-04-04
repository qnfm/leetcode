#include <string>
using namespace std;

class Solution
{
public:
    int maxDepth(string s)
    {
        int r = 0, cur = 0;
        for (auto &c : s)
        {
            if (c == '(')
                r = max(r, ++cur);
            if (c == ')')
                --cur;
        }
        return r;
    }
};