#include <vector>
using namespace std;
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        vector<int> r(3, 0);
        for (auto &t : triplets)
        {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            if (t[0] == target[0])
                r[0] = -1;
            if (t[1] == target[1])
                r[1] = -1;
            if (t[2] == target[2])
                r[2] = -1;
        }
        return r == vector<int>(3, -1);
    }
};