#include <vector>
using namespace std;
class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int lo = 1, hi, mid;
        for (auto v : piles)
            hi = max(hi, v);
        int r = hi;
        while (lo <= hi)
        {
            mid = lo + ((hi - lo) >> 1);
            unsigned long long hrs = 0;
            for (auto v : piles)
                hrs += ceil((double)v / mid);
            if (hrs <= h)
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