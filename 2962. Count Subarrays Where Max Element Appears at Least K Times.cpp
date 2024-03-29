#include <vector>
using namespace std;
class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int maxElem = *max_element(nums.begin(), nums.end());
        int slow = 0, fast = 0;
        long long r = 0;
        while (fast < nums.size())
        {
            if (nums[fast] == maxElem)
                k--;
            while (!k)
            {
                if (nums[slow] == maxElem)
                    k++;
                slow++;
            }
            r += slow;
            fast++;
        }
        return r;
    }
};