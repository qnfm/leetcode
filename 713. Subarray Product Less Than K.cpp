#include <vector>
using namespace std;

class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int r = 0;
        int slow = 0, fast = 0;
        long prod = 1;
        while (fast < nums.size())
        {
            prod *= nums[fast];
            while (prod >= k && slow <= fast)
            {
                prod /= nums[slow++];
            }
            r += fast - slow + 1;
            fast++;
        }
        return r;
    }
};