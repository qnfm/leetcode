#include <algorithm>
using namespace std;
class Solution
{
public:
    double myPow(double x, int n)
    {
        double cur = x;
        double r = 1;
        for (long i = abs(n); i > 0; i /= 2)
        {
            if (i % 2 == 1)
                r *= cur;
            cur *= cur;
        }
        if (n < 0)
            return 1.0 / r;
        return r;
    }
};