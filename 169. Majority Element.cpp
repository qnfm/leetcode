#include <vector>
#include <bitset>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {

        const int half = ceil(nums.size() / 2.0);
        bitset<32> r;
        for (int i = 0; i < 32; i++)
        {
            int zeros = 0;
            for (auto n : nums)
            {
                bitset<32> bits((unsigned int)abs(n));
                bits[31] = n < 0 ? 1 : 0;
                zeros += bits[i] ? 0 : 1;
            }
            if (zeros < half)
            {
                r[i] = 1;
            }
        }
        bool neg = r[31];
        r[31] = 0;
        return neg ? -r.to_ulong() : r.to_ulong();
    }
};