// 904. Fruit Into Baskets
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left=0, diffFruits=0;
        vector<int> freqs(fruits.size());
        for (int i=0; i<fruits.size(); ++i) {
            if (!freqs[fruits[i]]++)
                diffFruits++;
            if (diffFruits>2)
                diffFruits-=--freqs[fruits[left++]]==0;
        }
        return fruits.size()-left;
    }
};