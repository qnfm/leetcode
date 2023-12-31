// class Solution
// {
// public:
//     int numTrees(int n)
//     {
//         if (n <= 0)
//             return 0;
//         if (n < 3)
//             return n;
//         int sum = 0;
//         for (int i = 1; i <= n; i++)
//         {
//             int left = numTrees(i - 1), right = numTrees(n - i);
//             if (left > 0 && right > 0)
//                 sum += left * right;
//             else
//                 sum += left + right;
//         }
//         return sum;
//     }
// };

#include <unordered_map>

class Solution {
public:
    int numTrees(int n) {
        if(n <= 0) return 0;
        if(n < 3) return n;
        if(map.contains(n)) return map[n];
        int sum = 0;
        for(int i = 1; i <= n; i++){
            int left = numTrees(i - 1), right = numTrees(n - i);
            if(left >0 && right >0) sum+= left*right;
            else sum+=left + right;
        }
        map[n] = sum;
        return sum;
    }
private:
    std::unordered_map<int,int> map;
};