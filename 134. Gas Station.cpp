#include <vector>
using namespace std;
class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int sum = 0, pos = 0, totalsum = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            int diff = gas[i] - cost[i];
            sum += diff;
            totalsum += diff;
            if (sum < 0)
            {
                sum = 0;
                pos = i + 1;
            }
        }
        if (totalsum < 0)
            return -1;
        return pos;
    }
};