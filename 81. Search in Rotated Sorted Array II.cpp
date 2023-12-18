#include <vector>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int lo = 0, hi = nums.size() - 1, mid;
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) >> 1);
            if (target == nums[mid] || target == nums[lo] || target == nums[hi])
                return true;
            if (nums[lo] == nums[mid] && nums[hi] == nums[mid])
            {
                lo++;
                hi--;
            }
            else if (nums[lo] <= nums[mid])
            {
                if (target > nums[lo] && target < nums[mid])
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            else
            {
                if (target > nums[mid] && target < nums[hi])
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        return false;
    }
};