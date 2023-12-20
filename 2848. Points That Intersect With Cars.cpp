#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    int numberOfPoints(vector<vector<int>> &nums)
    {
        int r = 0;
        unordered_set<int> set;
        for (const auto &ns : nums)
        {
            for (int i = ns[0]; i <= ns[1]; i++)
            {
                set.insert(i);
            }
        }
        return set.size();
    }
};