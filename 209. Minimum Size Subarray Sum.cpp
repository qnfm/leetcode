// #include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int start = 0, end = 0, sum = 0;
        int r = INT_MAX;
        while (end < nums.size())
        {
            sum += nums[end];
            while (sum >= target && start <= end)
            {
                r = min(r, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return r == INT_MAX ? 0 : r;
    }
};