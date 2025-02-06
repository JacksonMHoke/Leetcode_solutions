// 1726. Tuple with Same Product
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int rt=0;
        unordered_map<int, int> prods;
        for (int i=0; i<nums.size(); ++i) {
            for (int j=i+1; j<nums.size(); ++j) {
                rt+=prods[nums[i]*nums[j]]*8;
                prods[nums[i]*nums[j]]++;
            }
        }
        return rt;
    }
};