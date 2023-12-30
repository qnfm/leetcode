// similar to 875. Koko Eating Bananas

#include <vector>
using namespace std;
class Solution
{
public:
    int minimizedMaximum(int n, vector<int> &quantities)
    {
        int hi = 1e5, lo = 1, mid, r = hi;
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) >> 1);
            int cnt = 0;
            for (const auto q : quantities)
                cnt += ceil((double)q / mid);
            if (n >= cnt)
            {
                r = min(r, mid);
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return r;
    }
};