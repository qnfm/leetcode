#include <unordered_set>
#include <vector>
using namespace std;
/*
Timeout
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> r;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(heights, i, j, heights[i][j], true) && dfs(heights, i, j, heights[i][j], false))
                    r.push_back({i, j});
            }
        }
        return r;
    }

private:
    int m, n;
    bool dfs(vector<vector<int>> &heights, int i, int j, int prev, bool dir)
    {
        if (dir && (i < 0 || j < 0))
            return true;
        if (!dir && (i > m - 1 || j > n - 1))
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] == -1 || heights[i][j] > prev)
            return false;

        int cur = heights[i][j];
        heights[i][j] = -1;
        bool r;
        r = dfs(heights, i - 1, j, cur, dir);
        r = dfs(heights, i + 1, j, cur, dir) || r;
        r = dfs(heights, i, j - 1, cur, dir) || r;
        r = dfs(heights, i, j + 1, cur, dir) || r;
        heights[i][j] = cur;
        return r;
    }
};
*/
/*Timeout 2
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> r;
        vi = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (vi[i][j] || (dfs(heights, i, j, heights[i][j], true) && dfs(heights, i, j, heights[i][j], false)))
                {
                    vi[i][j] = 1;
                    r.push_back({i, j});
                }
            }
        }
        return r;
    }

private:
    int m, n;
    vector<vector<int>> vi;

    bool dfs(vector<vector<int>> &heights, int i, int j, int prev, bool dir)
    {
        if (dir && (i < 0 || j < 0))
            return true;
        if (!dir && (i > m - 1 || j > n - 1))
            return true;
        if (i < 0 || i >= m || j < 0 || j >= n || heights[i][j] == -1 || heights[i][j] > prev)
            return false;
        if (vi[i][j])
            return true;
        int cur = heights[i][j];
        heights[i][j] = -1;
        bool r;
        r = dfs(heights, i - 1, j, cur, dir);
        r = dfs(heights, i + 1, j, cur, dir) || r;
        r = dfs(heights, i, j - 1, cur, dir) || r;
        r = dfs(heights, i, j + 1, cur, dir) || r;
        heights[i][j] = cur;
        return r;
    }
};
*/
class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> r;
        vector<vector<bool>> pacific(m, vector<bool>(n));
        vector<vector<bool>> atlantic(m, vector<bool>(n));
        vi = vector<vector<int>>(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (int j = 0; j < n; j++)
        {
            dfs(heights, pacific, 0, j);
            dfs(heights, atlantic, m - 1, j);
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (pacific[i][j] && atlantic[i][j])
                {
                    r.push_back({i, j});
                }
            }
        }

        return r;
    }

private:
    int m, n;
    vector<vector<int>> vi;
    void dfs(vector<vector<int>> &hei, vector<vector<bool>> &vi, int i, int j)
    {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return;
        vi[i][j] = true;
        if (i > 0 && !vi[i - 1][j] && hei[i - 1][j] >= hei[i][j])
            dfs(hei, vi, i - 1, j);
        if (i < m - 1 && !vi[i + 1][j] && hei[i + 1][j] >= hei[i][j])
            dfs(hei, vi, i + 1, j);
        if (j > 0 && !vi[i][j - 1] && hei[i][j - 1] >= hei[i][j])
            dfs(hei, vi, i, j - 1);
        if (j < n - 1 && !vi[i][j + 1] && hei[i][j + 1] >= hei[i][j])
            dfs(hei, vi, i, j + 1);
    }
};