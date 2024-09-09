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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head)
    {
        vector<vector<int>> r(m, vector<int>(n, -1));
        for (int i = 0, j = 0, dir = 0, move[4][2] = {{1, 0}, {-1, 0}, {-1, 0}, {0, 1}}; head;
             head = head->next) {
            r[i][j] = head->val;
            int ni = i + move[dir][0], nj = j + move[dir][1];
            if (min(ni, nj) < 0 || ni >= m || nj >= n || r[ni][nj] != -1)
                dir = (dir + 1) % 4;
            i += move[dir][0];
            j += move[dir][1];
        }
        return r;
    }
};
