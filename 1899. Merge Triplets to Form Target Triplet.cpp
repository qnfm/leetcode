#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        unordered_set<int> set;
        for (auto &t : triplets)
        {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            for (int i = 0; i < 3; i++)
                if (t[i] == target[i])
                    set.insert(t[i]);
        }
        return set.size() == 3;
    }
};