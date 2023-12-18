#include <cmath>
// class Solution
// {
// public:
//     int rangeBitwiseAnd(int left, int right)
//     {
//         int r = left;
//         while (left < right)
//         {
//             if (left == right && right == INT_MAX)
//                 return r;
//             r &= ++left;
//         }
//         return r;
//     }
// };

class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        if (left == 0)
            return 0;
        int bit1 = log2(left), bit2 = log2(right);
        if (bit1 < bit2)
            return 0;
        int msv = 1 << bit1;
        return msv | rangeBitwiseAnd(left ^ msv, right ^ msv);
    }
};