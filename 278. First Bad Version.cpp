#include <algorithm>
using namespace std;
// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int low = 0, high = n, mid, r = n;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            bool comp = isBadVersion(mid);
            if (comp)
            {
                r = min(r, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return r;
    }
};