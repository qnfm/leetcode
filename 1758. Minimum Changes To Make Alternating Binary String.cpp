#include <string>
using namespace std;
class Solution
{
public:
    int minOperations(string s)
    {
        int c1 = 0, c2 = 0;
        int ch1 = 0, ch2 = 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (ch1 != s[i] - '0')
                ++c1;
            if (ch2 != s[i] - '0')
                ++c2;
            ch1 = ch1 == 0 ? 1 : 0;
            ch2 = ch2 == 0 ? 1 : 0;
        }
        return min(c1, c2);
    }
};