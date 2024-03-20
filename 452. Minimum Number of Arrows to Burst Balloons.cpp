#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &P)
    {
        sort(P.begin(), P.end());
        pair<int, int> prev{P[0][0], P[0][1]};
        int r = 1;
        for (int i = 1; i < P.size(); ++i)
        {
            int xs = P[i][0], xe = P[i][1];
            if (prev.second >= xs)
            {
                prev = {min(prev.first, xs), min(prev.second, xe)};
            }
            else
            {
                prev = {xs, xe};
                ++r;
            }
        }
        return r;
    }
};