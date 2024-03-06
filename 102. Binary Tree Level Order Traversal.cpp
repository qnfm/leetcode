#include <vector>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> r;
        queue<TreeNode *> q;
        if (!root)
            return r;
        q.push(root);
        while (!q.empty())
        {
            vector<int> cur;
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                auto top = q.front();
                q.pop();
                cur.push_back(top->val);
                if (top->left)
                    q.push(top->left);
                if (top->right)
                    q.push(top->right);
            }
            r.push_back(cur);
        }
        return r;
    }
};