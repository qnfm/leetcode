#include <vector>
using namespace std;

// class Solution
// {
// public:
//     vector<int> findDuplicates(vector<int> &nums)
//     {
//         vector<int> r;
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             auto pos = nums[i] - 1;
//             while (nums[pos] != nums[i])
//             {
//                 swap(nums[pos], nums[i]);
//                 pos = nums[i] - 1;
//             }
//         }
//         for (int i = 0; i < nums.size(); ++i)
//         {
//             auto pos = nums[i] - 1;
//             if (nums[pos] == nums[i] && i != pos)
//                 r.push_back(nums[i]);
//         }
//         return r;
//     }
// };

class Solution
{
public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        vector<int> r;
        for (int i = 0; i < nums.size(); ++i)
        {
            auto pos = abs(nums[i]) - 1;
            if (nums[pos] < 0)
            {
                r.push_back(abs(nums[i]));
            }
            nums[pos] = -nums[pos];
        }
        return r;
    }
};