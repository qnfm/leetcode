#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        bool r = false;
        this->row = board.size();
        this->col = board[0].size();
        this->word = word;
        vector<vector<bool>> visit(row, vector<bool>(col, false));
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                r = r or dfs(board, visit, i, j, 0);
            }
        }
        return r;
    }

private:
    int row;
    int col;
    string word;
    bool dfs(vector<vector<char>> &board, vector<vector<bool>> visit, int i, int j, int k)
    {
        if (k == word.size())
            return true;
        if (i >= row or i < 0 or j >= col or j < 0 or k > word.size() or word[k] != board[i][j] or visit[i][j])
            return false;
        visit[i][j] = true;
        return dfs(board, visit, i - 1, j, k + 1) or dfs(board, visit, i + 1, j, k + 1) or dfs(board, visit, i, j - 1, k + 1) or dfs(board, visit, i, j + 1, k + 1);
    }
};