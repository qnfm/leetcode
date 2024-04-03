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
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (dfs(board, i, j, 0))
                    return true;
            }
        }
        return false;
    }

private:
    int row;
    int col;
    string word;
    bool dfs(vector<vector<char>> &board, int i, int j, int k)
    {
        if (i >= row or i < 0 or j >= col or j < 0 or k > word.size() or word[k] != board[i][j])
            return false;
        // already visit hte last character
        if (k == word.size() - 1)
            return true;
        board[i][j] = '#';
        if (dfs(board, i - 1, j, k + 1) or dfs(board, i + 1, j, k + 1) or dfs(board, i, j - 1, k + 1) or dfs(board, i, j + 1, k + 1))
            return true;
        board[i][j] = word[k];
        return false;
    }
};