#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<int> currComb;
        comb(candidates, target, 0, currComb);
        return r;
    }

private:
    vector<vector<int>> r;

    void comb(vector<int> &can, int target, int currIndex, vector<int> currComb)
    {
        if (target < 0)
            return;
        if (target == 0)
        {
            r.push_back(currComb);
            return;
        }
        for (int i = currIndex; i < can.size(); i++)
        {
            currComb.push_back(can[i]);
            comb(can, target - can[i], i, currComb);
            currComb.pop_back();
        }
    }
};