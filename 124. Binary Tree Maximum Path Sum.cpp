#include <algorithm>
#include <iostream>
#include <limits.h>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

using namespace std;
struct TreeNode
{
    int val;
    vector<TreeNode *> children;
};

// int dfs(TreeNode *root, int& maxPath)
// {
//     if (root == nullptr) return 0;
//     int curr = 0, maxChild = ((root->children).size() == 0) ? 0 : INT_MIN;
//     for (auto child : root->children){
//         int tmpMaxChild = dfs(child, maxPath);
//         tmpMaxChild = max(tmpMaxChild, 0);

//         maxChild = tmpMaxChild  + child->val;
//         curr += maxChild;
//     }
//     curr += root->val;
//     maxPath = max(maxPath, curr);
//     return maxChild;
// }

int dfs(TreeNode *root, int &maxPath)
{
    if (root == nullptr)
        return 0;
    int curr = 0;
    int firstMax = INT_MIN, secondMax = INT_MIN;
    if ((root->children).size() == 1)
    {
        firstMax = root->children[0]->val;
        secondMax = 0;
    }
    else
    {
        for (auto child : root->children)
        {
            int tmp = dfs(child, maxPath);
            tmp = max(tmp, 0) + child->val;
            if (tmp > firstMax)
            {
                secondMax = firstMax;
                firstMax = tmp;
            }
            else if (tmp > secondMax && tmp != firstMax)
                secondMax = tmp;
        }
    }
    curr = firstMax + secondMax + root->val;
    maxPath = max(maxPath, curr);
    return max(firstMax, secondMax);
}
int bestSumAnyTreePath(vector<int> &parents, vector<int> &values)
{
    unordered_map<int, TreeNode *> nodes;
    unordered_map<TreeNode *, int> vals;
    TreeNode *root;
    int maxPath = INT_MIN;
    for (int i = 0; i < values.size(); i++)
    {
        TreeNode *no = new TreeNode();
        no->val = values[i];
        nodes[i] = no;
        vals[no] = no->val;
    }

    for (int i = 0; i < parents.size(); i++)
    {
        if (parents[i] == -1)
            root = nodes[i];
        else
            nodes[parents[i]]->children.push_back(nodes[i]);
    }

    dfs(root, maxPath);
    return maxPath;
}

int main()
{
    // vector<int> parents = {-1, 0, 0, 0, 3, 4, 3};
    // vector<int> values = {-2, 8, 9, 10, -1, 2, 3};

    vector<int> parents = {-1, 0, 1, 0};
    vector<int> values = {-2, 9, 10, 8};

    // vector<int> parents = {-1, 0, 0};
    // vector<int> values = {-2, 9, 8};

    cout << bestSumAnyTreePath(parents, values) << endl;
    return 0;
}