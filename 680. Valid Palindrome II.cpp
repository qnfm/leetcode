#include <unordered_map>
#include <string>
using namespace std;
// class Solution
// {
// public:
//     bool validPalindrome(string s, int quota = 1)
//     {
//         int lo = 0, hi = s.size() - 1;
//         while (lo <= hi)
//         {
//             if (s[lo] != s[hi])
//             {
//                 return quota == 1 && ((lo <= hi - 1) && validPalindrome(s.substr(lo, hi - lo), quota - 1)) || (lo + 1 <= hi && validPalindrome(s.substr(lo + 1, hi - lo), quota - 1));
//             }
//             if (quota < 0)
//                 return false;
//             lo++;
//             hi--;
//         }
//         return true;
//     }
// };

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int lo = 0, hi = s.size() - 1;
        while (lo <= hi)
        {
            if (s[lo] != s[hi])
            {
                return helper(s, lo + 1, hi) || helper(s, lo, hi - 1);
            }
            lo++;
            hi--;
        }
        return true;
    }

private:
    bool helper(string s, int lo, int hi)
    {
        while (lo <= hi)
            if (s[lo++] != s[hi--])
                return false;
        return true;
    }
};
