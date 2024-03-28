#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int slow = 0, fast = 0;
        unordered_map<int, int> map;
        int r = 0;
        while (fast < nums.size())
        {
            map[nums[fast]]++;
            while (map[nums[fast]] > k)
            {
                map[nums[slow]]--;
                slow++;
            }
            r = max(r, fast - slow + 1);
            fast++;
        }
        return r;
    }
};