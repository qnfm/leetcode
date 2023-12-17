#include <string>
using namespace std;
class Solution
{
public:
    int titleToNumber(string columnTitle)
    {
        int r = 0;
        for (auto c : columnTitle)
        {
            int d = c - 'A' + 1;
            r = r * 26 + d;
        }
        return r;
    }
};