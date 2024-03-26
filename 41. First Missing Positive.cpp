#include <vector>
using namespace std;
class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        const size_t n = nums.size();
        bool contains = false;
        for (size_t i = 0; i < n; i++)
        {
            if (nums[i] == 1)
                contains = true;
            if (nums[i] <= 0 || nums[i] > n)
                nums[i] = 1;
        }

        if (!contains)
            return 1;

        for (size_t i = 0; i < n; i++)
        {
            int val = abs(nums[i]);
            if (val == n)
                nums[0] = -abs(nums[0]);
            else
                nums[val] = -abs(nums[val]);
        }

        for (size_t i = 1; i < n; i++)
            if (nums[i] > 0)
                return i;

        if (nums[0] > 0)
            return n;

        return n + 1;
    }
};