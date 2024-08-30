#include <vector>
using namespace std;
class Solution {
public:
    int numTeams(vector<int>& rating)
    {
        int sum = 0;
        vector<vector<int>> i(rating.size(), vector<int>(4, -1));
        vector<vector<int>> d(rating.size(), vector<int>(4, -1));
        for (int idx = 0; idx < rating.size(); idx++) {
            sum += dfs1(rating, idx, 1, i);
            sum += dfs2(rating, idx, 1, d);
        }
        return sum;
    }
    int dfs1(vector<int>& A, int i, int j, vector<vector<int>>& team)
    {
        if (i == A.size())
            return 0;
        if (j == 3)
            return 1;
        if (team[i][j] != -1)
            return team[i][j];
        int sum = 0;
        for (int next = i + 1; next < A.size(); next++) {
            if (A[next] > A[i]) {
                sum += dfs1(A, next, j + 1, team);
            }
        }

        return team[i][j] = sum;
    }

    int dfs2(vector<int>& A, int i, int j, vector<vector<int>>& team)
    {
        if (i == A.size())
            return 0;
        if (j == 3)
            return 1;
        if (team[i][j] != -1)
            return team[i][j];
        int sum = 0;
        for (int next = i + 1; next < A.size(); next++) {
            if (A[next] < A[i]) {
                sum += dfs2(A, next, j + 1, team);
            }
        }

        return team[i][j] = sum;
    }
};
