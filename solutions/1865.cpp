// 1865. Finding Pairs With a Certain Sum
class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        for (auto num : nums1)
            num1Freqs[num]++;
        for (auto num : nums2)
            num2Freqs[num]++;
        this->nums2=nums2;
    }
    
    void add(int index, int val) {
        int prev=nums2[index];
        nums2[index]+=val;
        num2Freqs[nums2[index]]++;
        num2Freqs[prev]--;
    }
    
    int count(int tot) {
        int rt=0;
        for (auto& [val, freq] : num1Freqs) {
            rt+=freq*(num2Freqs[tot-val]);
        }
        return rt;
    }
private:
    unordered_map<int, int> num1Freqs, num2Freqs;
    vector<int> nums2;
};