#include <vector>
#include <string>
#include <array>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        const int sz = words.size();
        array<int, 26> freq{0};
        for (const auto f : freq)
        cout << f;
        for (const auto &s : words)
            for (const auto c : s)
                freq[c - 'a']++;
        for (const auto f : freq)
            if (f && f % sz)
                return false;
        return true;
    }
};