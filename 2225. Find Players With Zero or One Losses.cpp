#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches)
    {
        vector<vector<int>> r(2);
        unordered_map<int, int> win, lost;
        for (auto &match : matches)
        {
            win[match[0]]++;
            lost[match[1]]++;
        }
        for (auto &[k, v] : win)
        {
            if (!lost.contains(k))
                r[0].push_back(k);
        }
        for (auto &[k, v] : lost)
        {
            if (v == 1)
                r[1].push_back(k);
        }
        sort(r[0].begin(), r[0].end());
        sort(r[1].begin(), r[1].end());
        return r;
    }
};