#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        vector<int> r(2);
        unordered_set<int> set;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += i - nums[i];
            if (set.contains(nums[i]))
            {
                r[0] = nums[i];
            }
            set.insert(nums[i]);
        }
        r[1] = sum + nums.size() + r[0];
        return r;
    }
};