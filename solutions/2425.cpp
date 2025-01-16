// 2425. Bitwise XOR of All Pairings
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int rt=0;
        for (int i=0; nums1.size()%2==1 && i<nums2.size(); ++i)
            rt^=nums2[i];
        for (int i=0; nums2.size()%2==1 && i<nums1.size(); ++i)
            rt^=nums1[i];
        return rt;
    }
};