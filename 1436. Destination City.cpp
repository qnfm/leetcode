#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> st;
        for (auto &vec : paths)
        {
            st.insert(vec[0]);
        }
        for (auto &vec : paths)
        {
            if (!st.contains(vec[1]))
                return vec[1];
        }
        return "";
    }
};