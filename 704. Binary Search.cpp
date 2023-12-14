#include <vector>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int mid, high = nums.size() - 1, low = 0;
        while (low <= high)
        {
            // due to operator precedence as below, the parentheses is a must
            // 5 	a*b   a/b   a%b 	Multiplication, division, and remainder
            // 6 	a+b   a-b 	Addition and subtraction
            // 7 	<<   >> 	Bitwise left shift and right shift
            mid = low + ((high - low) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return -1;
    }
};