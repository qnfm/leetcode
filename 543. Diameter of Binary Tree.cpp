#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        r = 0;
        dfs(root);
        return r;
    }

private:
    int r;
    int dfs(TreeNode *node)
    {
        if (!node)
            return 0;
        int left = dfs(node->left), right = dfs(node->right);
        this->r = max(this->r, left + right);
        return 1 + max(left, right);
    }
};