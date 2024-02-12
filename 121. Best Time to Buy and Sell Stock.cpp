#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int r = 0, low = INT_MAX;
        for (auto n : prices)
        {
            low = min(low, n);
            r = max(r, n - low);
        }
        return r;
    }
};