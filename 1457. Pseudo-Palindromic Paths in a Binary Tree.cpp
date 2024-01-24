#include <bit>
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
    int pseudoPalindromicPaths(TreeNode *root, int sum = 0)
    {
        if (root)
        {
            sum ^= 1 << root->val;
            if (!root->left && !root->right && (sum & sum - 1) == 0)
                ++r;
            pseudoPalindromicPaths(root->left, sum);
            pseudoPalindromicPaths(root->right, sum);
        }
        return r;
    }

private:
    int r = 0;
};