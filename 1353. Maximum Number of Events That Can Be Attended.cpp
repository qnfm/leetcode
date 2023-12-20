#include <vector>
#include <algorithm>
#include <set>
using namespace std;
class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [&](const auto &ea, const auto &eb)
             { return ea[1] != eb[1] ? ea[1] < eb[1] : ea[0] < eb[0]; });
        int cur = events[0][0], r = 0;
        set<int> sel;
        for (int i = 1; i <= 100000; i++)
            sel.insert(i);
        for (const auto &e : events)
        {

            auto it = sel.lower_bound(e[0]);
            if (it != sel.end() && *it <= e[1])
            {
                sel.erase(it);
                ++r;
            }
        }
        return r;
    }
};