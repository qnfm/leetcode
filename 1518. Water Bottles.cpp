class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int r = 0;
        while(numBottles >= numExchange){
            int k = numBottles   / numExchange;
            r += k * numExchange;
            numBottles -= numExchange * k;
            numBottles += k;
        }
        return r + numBottles;
    }
};
