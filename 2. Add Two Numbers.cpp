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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2, int carry = 0)
    {
        int sum = 0;
        if (l1 && l2)
        {
            sum = l1->val + l2->val + carry;
            carry = sum / 10;
            l1->val = sum % 10;
            l1->next = addTwoNumbers(l1->next, l2->next, carry);
            return l1;
        }
        else if (l1 || l2)
        {
            auto tmp = l1 ? l1 : l2;
            sum = tmp->val + carry;
            carry = sum / 10;
            tmp->val = sum % 10;
            tmp->next = addTwoNumbers(tmp->next, nullptr, carry);
            return tmp;
        }
        else if (carry > 0)
            return new ListNode(carry);
        return nullptr;
    }
};