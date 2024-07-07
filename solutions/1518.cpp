// 1518. Water Bottles
class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinken=0, remainder=0, empty=0;
        while (numBottles) {
            drinken+=numBottles;
            empty+=numBottles;
            numBottles=empty/numExchange;
            empty%=numExchange;
        }
        return drinken;
    }
};