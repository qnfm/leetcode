#include <vector>
using namespace std;
class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int first = INT_MAX, second = INT_MAX;
        for (auto v : prices)
        {
            if (v < first)
            {
                second = first;
                first = v;
            }
            else if (v >= first && v < second)
                second = v;
        }
        int leftover = money - first - second;
        return leftover >= 0 ? leftover : money;
    }
};