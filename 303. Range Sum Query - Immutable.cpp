#include <vector>
using namespace std;
class NumArray
{
public:
    NumArray(vector<int> &nums)
    {
        ns = nums;
        prefix = vector(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            prefix[i] = sum;
        }
    }

    int sumRange(int left, int right)
    {
        return prefix[right] - prefix[left] + ns[left];
    }

private:
    vector<int> prefix;
    vector<int> ns;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */