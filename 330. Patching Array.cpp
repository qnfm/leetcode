#include <vector>
using namespace std;

class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int i = 0;
        int r = 0;
        unsigned long long missing = 1;
        while (missing <= n) {
            if (i < nums.size() && nums[i] <= missing) {
                missing += nums[i++];
            } else {
                ++r;
                missing <<= 1;
            }
        }
        return r;
    }
};
