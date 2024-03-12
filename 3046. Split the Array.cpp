#include <array>
#include <vector>
using namespace std;
class Solution
{
public:
    bool isPossibleToSplit(vector<int> &nums)
    {
        array<int, 101> freq{};
        for (auto n : nums)
        {
            freq[n]++;
            if (freq[n] > 2)
                return false;
        }
        return true;
    }
};