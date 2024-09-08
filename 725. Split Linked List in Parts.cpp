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
    vector<ListNode*> splitListToParts(ListNode* head, int k)
    {
        int size = 0;
        ListNode* cur = head;
        while (cur) {
            ++size;
            cur = cur->next;
        }
        int rem = size % k;
        int bat = size / k;
        int emp = (size < k) ? k - size : 0;
        cur = head;
        ListNode* prev = new ListNode(-1, head);
        std::vector<ListNode*> r;
        while (cur) {
            r.push_back(cur);
            int needed = bat;
            if (rem > 0) {
                ++needed;
                --rem;
            }
            size -= needed;
            while (needed > 0) {
                prev = cur;
                cur = cur->next;
                --needed;
            }
            prev->next = nullptr;
        }
        if (emp > 0) {
            r.insert(r.end(), emp, nullptr);
        }
        return r;
    }
};
