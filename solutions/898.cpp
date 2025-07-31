// 898. Bitwise ORs of Subarrays
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> rt, prev;
        for (auto num : arr) {
            unordered_set<int> temp={num};
            for (auto prevNum : prev)
                temp.insert(prevNum|num);
            for (auto cand : temp)
                rt.insert(cand);
            prev=temp;
        }
        return rt.size();
    }
};