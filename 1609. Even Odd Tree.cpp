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
    bool isEvenOddTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        if (!root)
            return true;
        q.push(root);
        int level = 0;
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; i++)
            {
                auto cur = q.front();
                q.pop();
                tmp.push_back(cur->val);
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
            if (level & 1)
            {
                if (tmp.front() & 1)
                    return false;
                for (int i = 1; i < tmp.size(); i++)
                {
                    if (tmp[i - 1] <= tmp[i] || (tmp[i] & 1))
                        return false;
                }
            }
            else
            {
                if (!(tmp.front() & 1))
                    return false;
                for (int i = 1; i < tmp.size(); i++)
                {
                    if (tmp[i - 1] >= tmp[i] || !(tmp[i] & 1))
                        return false;
                }
            }
            level++;
        }
        return true;
    }
};