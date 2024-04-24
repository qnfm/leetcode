#include <utility>
using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 1;

        int n0 = 0, n1 = 1, n2 = 1, n3 = 0;
        for(int i = 3; i <= n; ++i){
            n3 = n0 + n1 + n2;
            swap(n0, n3);
            swap(n0, n1);
            swap(n1, n2);
        }
        return n2;
    }
};
