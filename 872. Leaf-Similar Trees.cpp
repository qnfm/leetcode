struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <vector>
using namespace std;
class Solution
{
public:
    bool leafSimilar(TreeNode *root1, TreeNode *root2)
    {
        vector<int> t1;
        vector<int> t2;
        dfs(root1, t1);
        dfs(root2, t2);
        return t1 == t2;
    }
    void dfs(TreeNode *node, vector<int> &v)
    {
        if (!node)
            return;
        if (!node->left && !node->right)
            v.push_back(node->val);
        else
        {
            dfs(node->left, v);
            dfs(node->right, v);
        }
    }
};