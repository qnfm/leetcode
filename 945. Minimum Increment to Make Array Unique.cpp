#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
  int minIncrementForUnique(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int r = 0;
    for (int i = 1; i < nums.size(); ++i) {
      int delta = nums[i - 1] - nums[i];
      if (delta >= 0) {
        nums[i] += 1 + delta;
        r += 1 + delta;
      }
    }
    return r;
  }
};
