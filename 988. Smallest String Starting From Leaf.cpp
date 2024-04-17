#include <string>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    string smallestFromLeaf(TreeNode* root, string cur = "") {
        if(!root) return r;
        cur = char(root->val + 'a') + cur;
        if(!root->left && !root->right){
            if(r == "" || cur < r){
                r = cur;
            }
        }
        if(root->left) smallestFromLeaf(root->left, cur);
        if(root->right) smallestFromLeaf(root->right, cur);
        return r;
    }
private:
    string r;
};