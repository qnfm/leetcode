#include <array>
#include <vector>
#include <string>
using namespace std;

class TrieNode
{
public:
    array<TrieNode *, 26> children;
    bool isword;
    TrieNode()
    {
        for (auto &ch : children)
            ch = nullptr;
        isword = false;
    }
};

class Solution
{
public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        vector<string> r;
        string cur;
        this->row = board.size();
        this->col = board[0].size();
        for (auto w : words)
            insert(w);

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                dfs(board, r, i, j, "", root);
            }
        }
        return r;
    }

private:
    TrieNode *root = new TrieNode();
    int row;
    int col;
    void insert(const string &word)
    {
        TrieNode *node = root;
        for (auto c : word)
        {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isword = true;
    }

    void dfs(vector<vector<char>> &board, vector<string> &r, int i, int j, string cur, TrieNode *node)
    {
        if (i < 0 || i >= row || j < 0 || j >= col || board[i][j] == '#')
            return;
        char c = board[i][j];
        cur += c;

        node = node->children[c - 'a'];
        if (!node)
            return;
        if (node->isword)
        {
            r.push_back(cur);
            node->isword = false;
        }
        board[i][j] = '#';
        dfs(board, r, i - 1, j, cur, node);
        dfs(board, r, i + 1, j, cur, node);
        dfs(board, r, i, j - 1, cur, node);
        dfs(board, r, i, j + 1, cur, node);
        board[i][j] = c;
    }
};