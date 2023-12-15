#include <vector>
using namespace std;
class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int lo = 0, hi = nums.size() - 1, mid, r = nums[0];
        if (nums[lo] <= nums[hi])
            return nums[lo];
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) >> 1);
            r = min(nums[mid], r);
            if (nums[mid] < nums[0])
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return r;
    }
};