#include <array>
#include <vector>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        array<bool, 100001> set{};
        for (auto &n : nums)
        {
            if (set[n])
                return n;
            set[n] = true;
        }
        return 0;
    }
};