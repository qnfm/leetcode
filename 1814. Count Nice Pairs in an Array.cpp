#include <unordered_map>
#include <vector>
using namespace std;
class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        unordered_map<int, int> map;
        for (auto &n : nums)
        {
            int rever = rev(n);
            n -= rever;
            map[n]++;
        }
        long long cnt = 0;
        const int mod = 1e9 + 7;
        for (auto &[k, v] : map)
        {
            if (v > 0)
            {
                cnt = (cnt + (((long long)v * (v - 1)) >> 1)) % mod;
            }
        }
        return (int)cnt;
    }

private:
    inline int rev(int a)
    {
        int b = 0;
        while (a > 0)
        {
            b = b * 10 + a % 10;
            a /= 10;
        }
        return b;
    }
};