// 260. Single Number III
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int x=0;
        for (auto num : nums)
            x^=num;
        x=(x==INT_MIN) ? 0 : x&-x;
        vector<int> rt{0, 0};
        for (auto num : nums) {
            if ((num&x)==0)
                rt[0]^=num;
            else
                rt[1]^=num;
        }
        return rt;
    }
};