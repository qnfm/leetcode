#include <vector>
using namespace std;
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int s = 1, f = 1;
        while (f < nums.size())
        {
            if (nums[f] != nums[f - 1])
            {
                nums[s] = nums[f];
                s++;
            }
            f++;
        }
        return s;
    }
};