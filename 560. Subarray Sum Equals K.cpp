#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int r = 0;
        int sum = 0;
        unordered_map<int, int> map;
        map[0]++;
        for (auto n : nums)
        {
            sum += n;
            auto delta = sum - k;
            if (map.contains(delta))
            {
                r += map[delta];
            }
            map[sum]++;
        }
        return r;
    }
};