#include <vector>
#include <unordered_map>
#include <unordered_set>
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
    TreeNode *createBinaryTree(vector<vector<int>> &d)
    {
        // val->Node*
        unordered_map<int, TreeNode *> map;
        unordered_set<int> check;
        int rootval;
        TreeNode *root = nullptr;
        for (const auto &no : d)
        {
            check.insert(no[1]);
            TreeNode *node = new TreeNode(no[1]);
            map[no[1]] = node;
        }

        for (const auto &no : d)
        {
            if (!check.contains(no[0]))
            {
                if (!root)
                {
                    rootval = no[0];
                    root = new TreeNode(no[0]);
                    map[rootval] = root;
                }
            }
            if (no[2] == 1)
                map[no[0]]->left = map[no[1]];
            else
                map[no[0]]->right = map[no[1]];
        }
        return map[rootval];
    }
};