#include <vector>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int r = 0, tmp = 0;
        for (const auto &n : nums)
        {
            if (n == 1)
                ++tmp;
            else
                tmp = 0;
            r = max(r, tmp);
        }
        return r;
    }
};