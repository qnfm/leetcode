#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(const vector<int> &nums)
    {
        vector<int> r(nums.size(), 1);
        int prefix = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            r[i] = prefix;
            prefix *= nums[i];
        }
        int postfix = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            r[i] *= postfix;
            postfix *= nums[i];
        }
        return r;
    }
};