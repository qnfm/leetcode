#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        long long sum = 0;
        for (auto n : nums)
            sum += n;
        // long long sum = std::accumulate(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 0;
        if (sum - nums.front() > nums.front())
            return sum;
        long long r = -1;
        while (i < nums.size())
        {
            if (sum - nums[i] > nums[i])
            {
                r = sum;
                break;
            }
            sum -= nums[i];
            i++;
        }
        return r;
    }
};