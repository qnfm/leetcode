#include<vector>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int r = 0;
        for(int i = 1; i < nums.size(); ++i){
            int delta = nums[i - 1] - nums[i];
            if(delta >= 0){
                nums[i] += delta + 1;
                r += delta + 1;
            }
        }
        return r;
    }
};
