#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        m = img.size();
        n = img[0].size();
        vector<vector<int>> r(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                r[i][j] = smooth(img, i, j);
            }
        }
        return r;
    }

private:
    int m;
    int n;
    inline int smooth(const auto &img, int ii, int jj)
    {
        int sum = 0, count = 0;
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int x = ii + i, y = jj + j;
                if (x >= 0 && x < m && y >= 0 && y < n)
                {
                    count++;
                    sum += img[x][y];
                }
            }
        }
        return sum / count;
    }
};