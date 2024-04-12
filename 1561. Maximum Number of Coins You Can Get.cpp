#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        const auto N = piles.size();
        int idx = N - 2;
        int r = 0;
        int cnt = N / 3;
        while (cnt > 0)
        {
            --cnt;
            r += piles[idx];
            idx -= 2;
        }
        return r;
    }
};