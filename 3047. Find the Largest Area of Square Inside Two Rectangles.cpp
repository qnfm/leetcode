#include <vector>
using namespace std;
class Solution
{
public:
    long long largestSquareArea(vector<vector<int>> &B, vector<vector<int>> &T)
    {
        int sz = B.size();
        long long r = 0;
        for (int i = 0; i < sz; i++)
        {
            for (int j = i + 1; j < sz; j++)
            {
                int height = min(T[i][1], T[j][1]) - max(B[i][1], B[j][1]);
                int width = min(T[i][0], T[j][0]) - max(B[i][0], B[j][0]);
                int sz = min(height, width);
                if (sz > 0)
                {
                    r = max(r, (long long)sz * sz);
                }
            }
        }
        return r;
    }
};