#include <algorithm>
#include <functional>
#include <utility>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int r = 0;
        vector<pair<int, int>> pd(profit.size());
        for(int i = 0; i < difficulty.size(); ++i){
            pd[i] = {profit[i],  difficulty[i]};
        }
        sort(pd.rbegin(), pd.rend());
        sort(worker.begin(),worker.end(), greater<int>());
        int i = 0, j = 0;
        while(i < worker.size() && j < pd.size()){
            if(worker[i] >= pd[j].second){
                r += pd[j].first;
                ++i;
            }else{
                ++j;
            }
        }
        return r;
    }
};
