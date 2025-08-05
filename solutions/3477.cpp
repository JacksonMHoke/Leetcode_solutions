// 3477. Fruits Into Baskets II
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool> used(fruits.size());
        int placed=0;
        for (int i=0; i<fruits.size(); ++i) {
            for (int j=0; j<fruits.size(); ++j) {
                if (!used[j] && baskets[j]>=fruits[i]) {
                    placed++;
                    used[j]=true;
                    break;
                }
            }
        }
        return fruits.size()-placed;
    }
};