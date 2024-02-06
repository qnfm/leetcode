#include <vector>
using namespace std;
    class Solution
    {
    public:
        bool isValidSudoku(vector<vector<char>> &board)
        {
            const int n = 9;
            vector<vector<bool>> row(n, vector<bool>(n, false));
            vector<vector<bool>> col(n, vector<bool>(n, false));
            vector<vector<bool>> sub(n, vector<bool>(n, false));

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (board[i][j] == '.')
                        continue;
                    int idx = board[i][j] - '0' - 1;
                    int subpos = (i / 3) * 3 + j / 3;
                    if (row[i][idx] || col[j][idx] || sub[subpos][idx])
                        return false;
                    row[i][idx] = true, col[j][idx] = true, sub[subpos][idx] = true;
                }
            }
            return true;
        }
    };
