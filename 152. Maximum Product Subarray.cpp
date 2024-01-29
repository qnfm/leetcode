#include <vector>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int prefix = 1, surfix = 1, r = INT_MIN;
        const int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            prefix *= nums[i];
            surfix *= nums[n - i - 1];
            int cur = max(prefix, surfix);
            r = max(r, cur);
            if (prefix == 0)
                prefix = 1;
            if (surfix == 0)
                surfix = 1;
        }
        return r;
    }
};