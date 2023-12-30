#include <string>
using namespace std;
class Solution
{
public:
    int removePalindromeSub(string s)
    {
        int lo = 0, hi = s.size() - 1;
        while (lo <= hi)
        {
            if (s[lo] != s[hi])
                return 2;
            lo++;
            hi--;
        }
        return 1;
    }
};