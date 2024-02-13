// naive
/*
class Solution {
public:
    void sortColors(vector<int>& nums) {
        array<unsigned short,3> buckets{};
        for(auto c : nums){
            buckets[c]++;
        }
        int j = 0;
        for(int i = 0; i < buckets.size(); i++){
           while(buckets[i] > 0){
               nums[j] = i;
               j++;
               buckets[i]--;
           }
        }
    }
};
*/
#include <vector>
using namespace std;
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int p0 = 0, p2 = nums.size() - 1, i = 0;
        while (i <= p2)
        {
            if (nums[i] == 0)
            {
                swap(nums[i++], nums[p0++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i], nums[p2--]);
            }
            else
                i++;
        }
    }
};