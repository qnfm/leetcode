#include <cmath>
using namespace std;
class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long long r = 0;
        int mod = 1e9 + 7;
        int len = 0;
        for (int i = 1; i <= n; i++)
        {
            int shift = log2(i) + 1;
            r = ((r << shift) % mod + i) % mod;
        }
        return r;
    }
};