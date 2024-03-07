#include <unordered_map>
#include <climits>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;
        unordered_map<Node *, Node *> map;
        map[nullptr] = nullptr;
        auto nh = new Node(head->val), cur = nh;
        map[head] = nh;
        while (head)
        {
            if (!map.contains(head->next))
                map[head->next] = new Node(head->next->val);
            if (!map.contains(head->random))
                map[head->random] = new Node(head->random->val);
            cur->next = map[head->next];
            cur->random = map[head->random];
            cur = cur->next;
            head = head->next;
        }
        return nh;
    }
};