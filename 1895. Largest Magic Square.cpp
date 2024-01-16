#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
    int largestMagicSquare(vector<vector<int>> &grid)
    {
        int rsz = grid.size(), csz = grid[0].size();
        rp = vector<vector<int>>(rsz, vector<int>(csz, 0));
        for (int i = 0; i < rsz; i++)
        {
            int sum = 0;
            for (int j = 0; j < csz; j++)
            {
                sum += grid[i][j];
                rp[i][j] = sum;
            }
        }

        cp = vector<vector<int>>(rsz, vector<int>(csz, 0));
        for (int i = 0; i < csz; i++)
        {
            int sum = 0;
            for (int j = 0; j < rsz; j++)
            {
                sum += grid[j][i];
                cp[j][i] = sum;
            }
        }

        dp = vector<vector<int>>(rsz, vector<int>(csz, 0));
        for (int col = 0; col < csz; col++)
        {
            int sum = 0, j = col, step = 0;
            for (int i = 0; i < rsz && j < csz; i++, j++)
            {
                sum += grid[i][j];
                dp[i][j] = sum;
                if (col == 0 && (i == rsz - 1 || j == csz - 1))
                {
                    i = ++step - 1;
                    j = col - 1;
                    continue;
                }
            }
        }

        adp = vector<vector<int>>(rsz, vector<int>(csz, 0));
        for (int col = csz - 1; col >= 0; col--)
        {
            int sum = 0, j = col, step = 0;
            for (int i = 0; i < rsz && j >= 0; i++, j--)
            {
                sum += grid[i][j];
                adp[i][j] = sum;
                if (col == csz - 1 && (i == rsz - 1 || j == 0))
                {
                    i = ++step - 1;
                    j = col + 1;
                    continue;
                }
            }
        }

        int r = 0;

        for (int i = 1; i <= rsz; i++)
        {
            for (int j = 1; j <= csz; j++)
            {
                for (int k = min(rsz - i, csz - j); k > r; --k)
                {
                    int sum = dp[i + k - 1][j + k - 1] - dp[i - 1][j - 1];
                    bool eq = sum == adp[i + k - 1][j -1] - adp[i - 1][j + k - 1];
                    if(eq){
                        for()
                    }
                }
            }
        }
    }

private:
    vector<vector<int>> &rp;
    vector<vector<int>> &cp;
    vector<vector<int>> &dp;
    vector<vector<int>> &adp;
};