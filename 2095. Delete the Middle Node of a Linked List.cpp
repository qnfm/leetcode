struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if (!prev)
            return prev;

        prev->next = prev->next->next;
        return head;
    }
};