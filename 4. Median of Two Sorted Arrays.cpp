#include <vector>
using namespace std;
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size();
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);
        int lo = 0, hi = m, total = m + n, i, j;
        double r = 0.0;
        while (lo <= hi)
        {
            i = lo + ((hi - lo) >> 1);
            j = (total + 1) / 2 - i;
            int left1 = (i > 0) ? nums1[i - 1] : INT_MIN;
            int right1 = (i < m) ? nums1[i] : INT_MAX;
            int left2 = (j > 0) ? nums2[j - 1] : INT_MIN;
            int right2 = (j < n) ? nums2[j] : INT_MAX;
            if (left1 <= right2 && left2 <= right1)
            {
                if (total & 1)
                    return max(left1, left2);
                else
                    return (max(left1, left2) + min(right1, right2)) / 2.0;
            }
            if (left1 > right2)
                hi = i - 1;
            else
                lo = i + 1;
        }
        return r;
    }
};