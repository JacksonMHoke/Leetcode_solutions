// 1310. XOR Queries of a Subarray
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefixXor(arr.size(), arr[0]);
        for (int i=1; i<arr.size(); ++i)
            prefixXor[i]=prefixXor[i-1]^arr[i];

        vector<int> rt;
        for (int i=0; i<queries.size(); ++i)
            rt.push_back(prefixXor[queries[i][1]]^prefixXor[queries[i][0]]^arr[queries[i][0]]);
        return rt;
    }
};