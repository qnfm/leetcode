#include <vector>
using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays)
    {
        int mx = *(arrays.begin()->end() - 1);
        int mm = *(arrays.begin()->begin());
        int r = 0;
        for (auto& vec : arrays) {
            if (vec == *arrays.begin())
                continue;
            r = max(r, max(*(vec.end() - 1) - mm, mx - *(vec.begin())));
            mm = min(mm, *vec.begin());
            mx = max(mx, *(vec.end() - 1));
        }
        return r;
    }
};
