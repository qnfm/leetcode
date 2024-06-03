#include <string>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0, j = 0;
        while(i < s.size() && j < t.size()){
            if(t[j] == s[i]){
                ++j;
            }
            ++i;
        }
        return t.size() - j;
    }
};