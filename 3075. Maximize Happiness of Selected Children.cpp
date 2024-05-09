#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &h, int k)
    {
        sort(h.begin(), h.end(), greater<int>());
        long long r = 0;
        int turn = 0;
        for (auto &n : h)
        {
            auto d = n - turn;
            if (d <= 0 || k <= 0)
                break;
            r += d;
            ++turn;
            --k;
        }
        return r;
    }
};