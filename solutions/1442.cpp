// 1442. Count Triplets That Can Form Two Arrays of Equal XOR
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> freq;
        int curr=0;
        for (int i=0; i<arr.size(); ++i) {
            curr^=arr[i];
            freq[curr].first+=i;
            freq[curr].second++;
        }

        int rt=freq[0].first;
        curr=0;
        for (int i=0; i<arr.size(); ++i) {
            curr^=arr[i];
            freq[curr].first-=i;
            freq[curr].second--;
            rt+=freq[curr].first-freq[curr].second*(i+1);
        }
        return rt;
    }
};