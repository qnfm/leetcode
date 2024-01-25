#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        const int n = nums.size();
        if (n == 1)
            return nums[0];
        return max(robrange(nums, 0, n - 2), robrange(nums, 1, n - 1));
    }

private:
    int robrange(vector<int> &n, int start, int end)
    {
        int cur = 0, prev = 0, next = 0;
        for (int i = start; i <= end; i++)
        {
            next = max(cur, prev + n[i]);
            prev = cur;
            cur = next;
        }
        return cur;
    }
};