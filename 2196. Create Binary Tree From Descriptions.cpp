#include <unordered_map>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode()
        : val(0)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
    TreeNode(int x, TreeNode* left, TreeNode* right)
        : val(x)
        , left(left)
        , right(right)
    {
    }
};
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions)
    {
        TreeNode* root = nullptr;
        unordered_map<int, TreeNode*> map;
        for (const auto& no : descriptions) {
            TreeNode* node = new TreeNode(no[1]);
            map[no[1]] = node;
        }

        for (const auto& no : descriptions) {
            if (!map.contains(no[0])) {
                root = new TreeNode(no[0]);
                map[no[0]] = root;
            }
            if (no[2]) {
                map[no[0]]->left = map[no[1]];
            } else {
                map[no[0]]->right = map[no[1]];
            }
        }
        return root;
    }
};
