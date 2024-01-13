#include <iostream>
#include <vector>
#include <string>
using namespace std;
void dfs(string &s, int idx, vector<vector<string>> &r, vector<string> cur)
{
    if (idx == s.size())
    {
        r.push_back(cur);
        return;
    }
    for (int i = idx; i < s.size(); i++)
    {
        cur.push_back(s.substr(idx, i - idx + 1));
        dfs(s, i + 1, r, cur);
        cur.pop_back();
    }
}
int main()
{
    vector<vector<string>> r;
    vector<string> cur;
    string s = "csl";
    dfs(s, 0, r, cur);
    for (auto &v : r)
    {
        auto last = v.end() - 1;
        for (auto it = v.begin(); it != v.end(); it++)
        {
            cout << *it;
            if (it != last)
                cout << ",";
        }
        cout << endl;
    }
    return 0;
}