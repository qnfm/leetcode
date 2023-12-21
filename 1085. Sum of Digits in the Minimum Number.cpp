#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int sumOfDigits(vector<int> &nums)
    {
        int s = INT_MAX;
        for (const auto &v : nums)
            s = min(s, v);
        int sum = 0;
        while (s != 0)
        {
            sum += s % 10;
            s /= 10;
        }
        return sum & 1 ? 0 : 1;
    }
};