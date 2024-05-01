#include <bit>
#include <vector>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int> &nums, int k)
    {
        for (auto &n : nums)
        {
            k ^= n;
        }
        return popcount((unsigned long)k);
    }
};