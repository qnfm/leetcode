#include <vector>
#include <algorithm>
#include <set>
using namespace std;
!
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
/*
[[1,2],[1,2],[3,3],[1,5],[1,5]]
[[1,5],[1,5],[1,5],[2,3],[2,3]]
[[1,3],[1,3],[1,3],[3,4]]
[[26,27],[24,26],[1,4],[1,2],[3,6],[2,6],[9,13],[6,6],[25,27],[22,25],[20,24],[8,8],[27,27],[30,32]]
[[1,2],[2,3],[3,4],[1,2]]
[[1,2],[2,3],[3,4]]
*/