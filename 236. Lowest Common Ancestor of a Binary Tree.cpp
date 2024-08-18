#define NULL nullptr
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        dfs(root, p, q);
        return r;
    }

private:
    TreeNode* r = NULL;
    bool dfs(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if (!node)
            return false;
        bool left = dfs(node->left, p, q);
        bool right = dfs(node->right, p, q);
        bool mid = node == p || node == q;
        if ((int)left + (int)right + (int)mid >= 2)
            r = node;
        return left || right || mid;
    }
};
