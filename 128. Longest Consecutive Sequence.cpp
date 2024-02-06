#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> set(nums.begin(), nums.end());
        int r = 0;
        for (auto n : nums)
        {
            if (!set.contains(n - 1))
            {
                int curlen = 1;
                while (set.contains(n + curlen))
                {
                    curlen++;
                }
                r = max(r, curlen);
            }
        }
        return r;
    }
};