#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int subarraysWithKDistinct(vector<int> &nums, int k)
    {
        return AtMost(nums, k) - AtMost(nums, k - 1);
    }
    int AtMost(vector<int> &n, int k)
    {
        int cnt = 0;
        unordered_map<int, int> map;
        int l = 0, r = 0;
        while (r < n.size())
        {
            map[n[r]]++;
            while (map.size() > k)
            {
                map[n[l]]--;
                if (map[n[l]] == 0)
                    map.erase(n[l]);
                ++l;
            }
            cnt += r - l + 1;
            r++;
        }
        return cnt;
    }
};