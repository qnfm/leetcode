#include <climits>
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
    int goodNodes(TreeNode *root, int cur = INT_MIN)
    {
        if (!root)
            return 0;
        int r = 0;
        if (root->val >= cur)
        {
            ++r;
            cur = root->val;
        }
        return r + goodNodes(root->left, cur) + goodNodes(root->right, cur);
    }
};