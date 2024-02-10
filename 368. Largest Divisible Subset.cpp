#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return {};

        vector<vector<int>> EDS(n);

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; ++i)
        {
            vector<int> maxSubset;

            for (int k = 0; k < i; ++k)
                if (nums[i] % nums[k] == 0 && maxSubset.size() < EDS[k].size())
                    maxSubset = EDS[k];

            EDS[i] = maxSubset;
            EDS[i].push_back(nums[i]);
        }

        vector<int> ret;
        for (int i = 0; i < n; ++i)
            if (ret.size() < EDS[i].size())
                ret = EDS[i];
        return ret;
    }
};