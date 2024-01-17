#include <vector>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

class Solution
{
public:
    Node *cloneTree(Node *root)
    {
        if (!root)
            return nullptr;
        Node *cur = new Node(root->val);
        for (auto ch : root->children)
            cur->children.push_back(cloneTree(ch));
        return cur;
    }
};