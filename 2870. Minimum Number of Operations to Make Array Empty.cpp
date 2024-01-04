#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto v : nums)
            map[v]++;
        int r = 0;
        for (const auto &[k, v] : map)
        {
            if (v == 1)
                return -1;
            if (v == 2)
                r++;
            else
            {
                r += ceil((double)v / 3);
            }
        }
        return r;
    }
};