#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int sum = 0, start = 0, end = 0;
        int r = 0;
        unordered_set<int> set;
        while (end < nums.size())
        {
            while (set.contains(nums[end]) && start < end)
            {
                // r = max(r, sum);
                set.erase(nums[start]);
                sum -= nums[start];
                start++;
            }
            sum += nums[end];
            r = max(r, sum);
            set.insert(nums[end]);
            end++;
        }
        return r;
    }
};