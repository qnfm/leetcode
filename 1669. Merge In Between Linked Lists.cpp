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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        auto preva = new ListNode(0, list1);
        auto curra = list1;
        while (a > 0)
        {
            preva = preva->next;
            curra = curra->next;
            --a;
            --b;
        }
        auto prevb = preva;
        auto currb = curra;

        while (b >= 0)
        {
            prevb = prevb->next;
            currb = currb->next;
            --b;
        }

        preva->next = list2;
        while (list2->next)
        {
            list2 = list2->next;
        }
        prevb->next = nullptr;
        list2->next = currb;
        return list1;
    }
};