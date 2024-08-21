#include <vector>
using namespace std;
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k)
    {
        vector<int> prefix(nums.size(), 0);
        for (int i = 0; i < nums.size() + 1; i++) {
            prefix[i + 1] = prefix[i] + (nums[i] & 1) ? 1 : 0;
        }
    }
};
