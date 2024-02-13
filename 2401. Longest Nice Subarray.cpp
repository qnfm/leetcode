#include <vector>
using namespace std;
class Solution
{
public:
    int longestNiceSubarray(vector<int> &nums)
    {
        int mask = 0;
        int l = 0, r = 0;
        int len = 0;
        while (r < nums.size())
        {
            while ((mask & nums[r]) != 0)
                mask ^= nums[l++];
            mask |= nums[r];
            len = max(len, r - l + 1);
            r++;
        }
        return len;
    }
};