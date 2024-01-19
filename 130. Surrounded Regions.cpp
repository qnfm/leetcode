#include <vector>
using namespace std;
class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        m = board.size();
        n = board[0].size();
        if (m < 3 || n < 3)
            return;
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
                dfs(board, i, 0, 'M');
            if (board[i][n - 1] == 'O')
                dfs(board, i, n - 1, 'M');
        }
        for (int j = 0; j < n; j++)
        {
            if (board[0][j] == 'O')
                dfs(board, 0, j, 'M');
            if (board[m - 1][j] == 'O')
                dfs(board, m - 1, j, 'M');
        }
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == 'M')
                    board[i][j] = 'O';
    }

private:
    int m, n;
    void dfs(vector<vector<char>> &A, int i, int j, char c)
    {
        if (i < 0 || i >= m || j < 0 || j >= n || A[i][j] == 'X' || A[i][j] == 'M')
            return;
        if (A[i][j] == 'O')
            A[i][j] = c;
        dfs(A, i - 1, j, c);
        dfs(A, i + 1, j, c);
        dfs(A, i, j + 1, c);
        dfs(A, i, j - 1, c);
    }
};