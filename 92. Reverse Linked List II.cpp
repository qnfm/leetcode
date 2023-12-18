#include <vector>
using namespace std;
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (left == right)
            return head;
        // left < right
        vector<ListNode *> list;
        ListNode *curr = head;
        while (curr)
        {
            list.push_back(curr);
            curr = curr->next;
        }
        reverse(list.begin() + left - 1, list.begin() + right);
        int i;
        for (i = 0; i < list.size() - 1; i++)
            list[i]->next = list[i + 1];
        list[i]->next = nullptr;

        return list[0];
    }
};