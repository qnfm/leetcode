#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> lets, digs;
        for (auto &log : logs)
        {
            size_t pos = log.find(" ");
            string first = log.substr(pos + 1);
            if (isalpha(first[0]))
                lets.push_back(log);
            else
                digs.push_back(log);
        }
        sort(lets.begin(), lets.end(), letcomp);
        lets.insert(lets.end(), digs.begin(), digs.end());
        return lets;
    }

private:
    struct
    {
        bool operator()(const auto &a, const auto &b) const
        {
            size_t posa = a.find(" "), posb = b.find(" ");
            string contenta = a.substr(posa + 1);
            string contentb = b.substr(posb + 1);
            ;
            if (contenta != contentb)
                return contenta < contentb;
            contenta = a.substr(0, posa);
            contentb = b.substr(0, posb);
            return contenta < contentb;
        }
    } letcomp;
};