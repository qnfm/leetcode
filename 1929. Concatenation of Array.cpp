#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> getConcatenation(vector<int> &nums)
    {
        vector<int> r(nums.begin(), nums.end());
        r.insert(r.end(), nums.begin(), nums.end());
        r.insert(r.end(), nums.begin(), nums.end());
        return r;
    }
};