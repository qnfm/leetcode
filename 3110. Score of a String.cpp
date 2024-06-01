#include <string>
using namespace std;

class Solution
{
public:
    int scoreOfString(string s)
    {
        int r = 0;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            r += abs(s[i] - s[i + 1]);
        }
        return r;
    }
};