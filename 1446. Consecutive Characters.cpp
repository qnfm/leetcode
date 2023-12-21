#include <string>
using namespace std;
// class Solution
// {
// public:
//     int maxPower(string s)
//     {
//         if (s.size() == 1)
//             return 1;
//         int cur = 1, r = 1;
//         for (int i = 1; i < s.size(); i++)
//         {
//             if (s[i] == s[i - 1])
//                 ++cur;
//             else
//                 cur = 0;
//             r = max(r, cur);
//             cur = 1;
//             if (i == s.size())
//                 return r;
//         }
//         return r;
//     }
// };

class Solution
{
public:
    int maxPower(string s)
    {
        int cur = 0, r = 0;
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
                ++cur;
            else
                cur = 0;
            r = max(r, cur);
        }
        return max(r, cur) + 1;
    }
};