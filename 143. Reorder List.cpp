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
    void reorderList(ListNode *head)
    {
        auto slow = head, fast = head->next;
        // if(!fast) return slow;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto second = slow->next;
        slow->next = nullptr;
        auto prev = slow->next;

        while (second)
        {
            auto tmp = second->next;
            second->next = prev;
            prev = second;
            second = tmp;
        }

        second = prev;
        auto first = head;
        while (second)
        {
            auto tmp1 = first->next, tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};