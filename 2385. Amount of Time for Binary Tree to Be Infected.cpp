struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <algorithm>
using namespace std;
class Solution
{
public:
    int amountOfTime(TreeNode *root, int start)
    {
        this->start = start;
        dfs(root);
        return this->maxdist;
    }

private:
    int maxdist = 0;
    int start;
    int dfs(TreeNode *root)
    {
        int depth = 0;
        if (!root)
            return depth;
        int left = dfs(root->left), right = dfs(root->right);
        if (root->val == this->start)
        {
            maxdist = max(left, right);
            depth = -1;
        }
        else if (left >= 0 && right >= 0)
        {
            depth = max(left, right) + 1;
        }
        else
        {
            int dist = abs(left) + abs(right);
            maxdist = max(maxdist, dist);
            depth = min(left, right) - 1;
        }
        return depth;
    }
};
