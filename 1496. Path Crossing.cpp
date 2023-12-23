/*
https://medium.com/@gulshansharma014/call-to-implicitly-deleted-default-constructor-of-unordered-map-pair-int-int-int-d3b2a6da0b41
https://stackoverflow.com/questions/62869571/call-to-implicitly-deleted-default-constructor-of-unordered-set-vectorint
*/
#pragma GCC optimize("O3", "unroll-loops")
#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isPathCrossing(string path)
    {
        unordered_set<string> visit;
        int x = 0, y = 0;
        visit.insert("0,0");
        for (const auto &c : path)
        {
            switch (c)
            {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            }
            string p = to_string(x) + "," + to_string(y);
            if (visit.contains(p))
                return true;
            else
                (visit.insert(p));
        }
        return false;
    }
};

auto init = []()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();