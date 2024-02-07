#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &n, int target)
    {
        int i = 0, j = n.size() - 1;
        while (i <= j)
        {
            int sum = n[i] + n[j];
            if (sum < target)
            {
                i++;
            }
            else if (sum > target)
            {
                j--;
            }
            else
                return {i + 1, j + 1};
        }
        return {};
    }
};