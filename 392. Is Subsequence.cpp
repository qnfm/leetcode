#include <string>
using namespace std;
class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        const int szs = s.size(), szt = t.size();
        if (szs > szt)
            return false;
        if (s == "")
            return true;
        int i = 0, j = 0;
        while (j < szt)
        {
            if (i < szs && s[i] == t[j])
            {
                i++;
            }
            j++;
        }
        return i == szs;
    }
};