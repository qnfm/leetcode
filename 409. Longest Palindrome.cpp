#include <bit>
#include <string>
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        unsigned long lo = 0, up = 0;
        for (const auto &c : s)
        {
            if (islower(c))
                lo ^= 1 << (c - 'a');
            else
                up ^= 1 << (c - 'A');
        }
        int odd = popcount(lo) + popcount(up);
        return (odd > 0 ? 1 : 0) + s.size() - odd;
    }
};