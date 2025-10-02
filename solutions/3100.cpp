// 3100. Water Bottles II
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drunken=0;
        while (numBottles>=numExchange) {
            drunken+=numExchange;
            numBottles-=(numExchange++-1);
        }
        return drunken+numBottles;
    }
};