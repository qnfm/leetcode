#include <vector>
using namespace std;

class Solution
{
public:
    int timeRequiredToBuy(vector<int> &tickets, int k)
    {
        int r = 0;
        for (int i = 0; i < tickets.size(); ++i)
        {
            if (i <= k)
            {
                r += min(tickets[i], tickets[k]);
            }
            else
                r += min(tickets[i], tickets[k] - 1);
        }
        return r;
    }
};