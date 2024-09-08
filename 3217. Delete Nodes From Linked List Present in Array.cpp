#include <unordered_set>
#include <vector>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
};

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head)
    {
        unordered_set<int> chk;
        for (int v : nums) {
            chk.insert(v);
        }
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* cur = dummy->next;

        while (cur) {
            if (chk.contains(cur->val)) {
                prev->next = cur->next;
                cur = prev->next;
            } else {
                prev = cur;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
