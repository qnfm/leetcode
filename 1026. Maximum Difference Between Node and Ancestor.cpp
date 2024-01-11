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
/*
class Solution {
public:
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        dfs(root,root->val);
        return maxdiff;
    }
    void dfs(TreeNode* root, int anc){
        if(!root) return;
        maxdiff = max(abs(anc - root->val), maxdiff);
        dfs(root->left, anc);
        dfs(root->left, root->val);
        dfs(root->right, root->val);
        dfs(root->right, anc);
    }
private:
    int maxdiff = 0;
};
*/

class Solution
{
public:
    int maxAncestorDiff(TreeNode *root)
    {
        if (!root)
            return 0;
        dfs(root, root->val, root->val);
        return diff;
    }
    void dfs(TreeNode *root, int low, int high)
    {
        if (!root)
            return;
        int curdiff = max(abs(root->val - low), abs(root->val - high));
        diff = max(diff, curdiff);
        low = min(root->val, low);
        high = max(root->val, high);
        dfs(root->left, low, high);
        dfs(root->right, low, high);
    }

private:
    int diff = 0;
};