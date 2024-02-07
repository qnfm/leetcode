#include <algorithm>
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        string r;
        unordered_map<char, int> freq;
        for (auto c : s)
            freq[c]++;
        vector<pair<char, int>> pairs;
        for (auto &[k, v] : freq)
            pairs.push_back({k, v});
        sort(pairs.begin(), pairs.end(), [](const auto &a, const auto &b)
             { return a.second > b.second; });
        for (auto &p : pairs)
        {
            string cur(p.second, p.first);
            r.insert(r.end(), cur.begin(), cur.end());
        }
        return r;
    }
};

// bucket sort
class Solution2 {
public:
    string frequencySort(string s) {
        string r;
        const int sz = s.size();
        unordered_map<char,int> map;
        for(auto c : s) map[c]++;
        vector<vector<char>> buckets(sz + 1);
        for(auto& [k,v] : map){
            buckets[v].push_back(k);
        }
        for(int i = sz; i >= 0; i--){
            if(!buckets[i].empty()){
                for(auto c: buckets[i]){
                    string cur(i,c);
                    r.insert(r.end(),cur.begin(),cur.end());
                }
            }
        }
        return r;
    }
};