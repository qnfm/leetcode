#include <vector>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        const int sz = prices.size();
        if (sz == 0)
            return 0;
        int lastbuy = -prices[0], lastsold = 0;
        for (int i = 1; i < sz; i++)
        {
            int curbuy = max(lastbuy, lastsold - prices[i]);
            int cursold = max(lastsold, lastbuy + prices[i]);
            lastbuy = curbuy;
            lastsold = cursold;
        }
        return lastsold;
    }
};