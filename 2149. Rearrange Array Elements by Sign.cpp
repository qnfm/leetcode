#include <vector>
#include <queue>
using namespace std;
class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        queue<int> q1, q2;
        for (auto n : nums)
        {
            if (n < 0)
                q1.push(n);
            else
                q2.push(n);
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 1)
            {
                nums[i] = q1.front();
                q1.pop();
            }
            else
            {
                nums[i] = q2.front();
                q2.pop();
            }
        }
        return nums;
    }
};