#include<vector>
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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(auto n : to_delete){
            dfs(root, n);
        }
        TreeNode* dummy = new TreeNode(0, root, nullptr);
        dfs2(dummy);
        return r;
    }
private:
    vector<TreeNode*> r;
    bool dfs(TreeNode* root, const int n){
        if(!root) return false;
        if(root->val == n){
            root->val = 0;
            return true;
        }
        if(!dfs(root->left, n)){
            return dfs(root->right, n);
        }
        return true;
    }
    void dfs2(TreeNode* root){
        if(!root) return;
        if(root->val == 0){
            if(root->left && root->left->val != 0)
                r.push_back(root->left);
            if(root->right && root->right->val != 0)
                r.push_back(root->right);
        }
        dfs2(root->left);
        dfs2(root->right);
    }
};
