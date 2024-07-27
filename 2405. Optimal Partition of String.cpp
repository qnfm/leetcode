#include <string>
using namespace std;
// class Solution
// {
// public:
//     int partitionString(string s)
//     {
//         int mask = 0, i = 0;
//         int res = 1;
//         while (i < s.size())
//         {
//             int val = 1 << (s[i] - 'a');
//             if (mask & val)
//             {
//                 mask = 0;
//                 res++;
//             }
//             mask ^= val;
//             ++i;
//         }
//         return res;
//     }
// };

class Solution {
public:
    int partitionString(string s)
    {
        int mask = 0;
        int r = 0;
        for (auto c : s) {
            int idx = 1 << (c - 'a');
            if (mask & idx) {
                ++r;
                mask = 0;
            }
            mask ^= idx;
        }
        return mask == 0 ? r : r + 1;
    }
};