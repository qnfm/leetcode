struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeZeroSumSublists(ListNode *head)
    {
        auto front = new ListNode(0, head);
        auto start = front;

        while (start)
        {
            int prefix = 0;
            auto end = start->next;
            while (end)
            {
                prefix += end->val;
                if (prefix == 0)
                {
                    start->next = end->next;
                }
                end = end->next;
            }
            start = start->next;
        }
        return front->next;
    }
};