#include <unordered_set>
#include <vector>
using namespace std;
class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> set;
        for (auto n : nums)
        {
            if (set.contains(n))
                return true;
            set.insert(n);
        }
        return false;
    }
};