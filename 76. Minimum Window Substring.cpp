#include <unordered_map>
#include <string>
using namespace std;
class Solution
{
public:
    string minWindow(string s, string t)
    {
        int i = 0, j = 0, minstart = 0, minwin = INT_MAX, count = t.size();
        unordered_map<char, int> freq;
        for (auto c : t)
            freq[c]++;
        while (j < s.size())
        {
            char cur = s[j];
            if (freq[cur] > 0)
                count--;
            freq[cur]--;
            j++;
            while (count == 0)
            {
                if (j - i < minwin)
                {
                    minstart = i;
                    minwin = j - i;
                }
                freq[s[i]]++;
                if (freq[s[i]] > 0)
                    count++;
                i++;
            }
        }
        if (minwin == INT_MAX)
            return "";
        return s.substr(minstart, minwin);
    }
};