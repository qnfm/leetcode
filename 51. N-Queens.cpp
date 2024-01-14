#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        vector<string> cur;
        vector<vector<string>> r;
        dfs(r, 0, cur);
        return r;
    }

private:
    int n;

    void dfs(vector<vector<string>> &r, int idx, vector<string> &cur)
    {
        if (idx == this->n && cur.size() == this->n)
        {
            r.push_back(cur);
            return;
        }
        string thisline(this->n, '.');
        for (int i = 0; i < this->n; i++)
        {
            if (!cur.empty())
            {
                int x = idx - 1, y = i;
                bool skip = false;
                while (x >= 0)
                {
                    if (cur[x--][y] == 'Q')
                    {
                        skip = true;
                        break;
                    }
                }
                if (skip)
                    continue;
                x = idx - 1;
                y = i - 1;
                while (x >= 0 && y >= 0)
                {
                    if (cur[x--][y--] == 'Q')
                    {
                        skip = true;
                        break;
                    }
                }
                if (skip)
                    continue;
                x = idx - 1;
                y = i + 1;
                while (x >= 0 && y < this->n)
                {
                    if (cur[x--][y++] == 'Q')
                    {
                        skip = true;
                        break;
                    }
                }
                if (skip)
                    continue;
            }
            thisline[i] = 'Q';
            cur.push_back(thisline);
            dfs(r, idx + 1, cur);
            cur.pop_back();
            thisline[i] = '.';
        }
    }
};
int main()
{
    Solution s;
    auto r = s.solveNQueens(4);
    for (auto rone : r)
    {
        for (auto s : rone)
            cout << s << endl;
        cout << endl;
    }
}