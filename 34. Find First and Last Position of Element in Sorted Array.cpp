#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int l = 0, h = nums.size() - 1, mid;
        vector<int> r(2, -1);
        while (l <= h)
        {
            mid = (h + l) / 2;
            if (target == nums[mid])
            {
                if (target == nums[l])
                {
                    r[0] = l;
                    break;
                }
                else if (mid > 0 && nums[mid - 1] != target)
                {
                    r[0] = mid;
                    break;
                }
                // if(target == nums[l] || (mid > 0 && nums[mid - 1] != target)){
                //     r[0] = l;
                //     break;
                // }
                else
                    h = mid - 1;
            }
            else if (target < nums[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }
        if (r[0] < 0)
            return {-1, -1};
        l = 0, h = nums.size() - 1;
        while (l <= h)
        {
            mid = (h + l) / 2;
            if (target == nums[mid])
            {
                if (target == nums[h])
                {
                    r[1] = h;
                    return r;
                }
                else if (mid < nums.size() - 1 && nums[mid + 1] != target)
                {
                    r[1] = mid;
                    return r;
                }
                else
                    l = mid + 1;
            }
            else if (target < nums[mid])
                h = mid - 1;
            else
                l = mid + 1;
        }

        return {-1, -1};
    }
};