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
    bool isPalindrome(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        fast = rev(slow);

        slow = head;

        while (fast)
        {
            if (slow->val != fast->val)
                return false;
            fast = fast->next;
            slow = slow->next;
        }
        return true;
    }

private:
    ListNode *rev(ListNode *root)
    {
        ListNode *prev = nullptr;
        ListNode *curr = root;
        while (curr)
        {
            auto tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }
        return prev;
    }
};