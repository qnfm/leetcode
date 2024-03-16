#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int r = 0;
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
            else
                cnt--;
            nums[i] = cnt;
            if (map.contains(cnt))
            {
                r = max(r, i - map[cnt]);
            }
            else
                map[cnt] = i;
            if (cnt == 0)
                r = max(r, i + 1);
        }
        return r;
    }
};