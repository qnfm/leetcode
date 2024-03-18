#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int left = 0, right = nums.size() - 1, k = right;
        vector<int> r(nums.size());
        while (left <= right)
        {
            int sql = nums[left] * nums[left];
            int sqr = nums[right] * nums[right];
            if (sql >= sqr)
            {
                left++;
                r[k--] = sql;
            }
            else
            {
                right--;
                r[k--] = sqr;
            }
        }
        return r;
    }
};