#include <vector>
#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node *cloneGraph(Node *node)
    {
        if (vi.contains(node))
            return vi[node];
        Node *cur = new Node(node->val);
        vi[node] = cur;
        for (auto ch : node->neighbors)
            cur->neighbors.push_back(cloneGraph(ch));
        return cur;
    }

private:
    unordered_map<Node *, Node *> vi{{nullptr, nullptr}};
};