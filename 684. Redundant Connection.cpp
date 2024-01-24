#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {
        const int n = edges.size();
        pare = vector<int>(n + 1);
        rank = vector<int>(n + 1, 1);
        for (int i = 0; i < edges.size() + 1; i++)
            pare[i] = i;
        for (auto &e : edges)
        {
            if (!Union(e[0], e[1]))
                return {e[0], e[1]};
        }
        return {0, 0};
    }

private:
    vector<int> pare, rank;
    int findpare(int x)
    {
        if (x == pare[x])
            return x;
        return pare[x] = findpare(pare[x]);
    }
    bool Union(int x, int y)
    {
        int r1 = findpare(x), r2 = findpare(y);
        if (r1 == r2)
            return false;
        if (rank[r1] < rank[r2])
            swap(r1, r2);
        rank[r1]++;
        pare[r2] = r1;
        return true;
    }
};