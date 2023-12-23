#include <vector>
using namespace std;
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int i = 0;
        for (const auto n : nums)
        {
            if (n != val)
                nums[i++] = n;
        }
        return i;
    }
};