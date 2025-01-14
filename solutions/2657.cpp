// 2657. Find the Prefix Common Array of Two Arrays
class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size(), common=0;
        vector<int> map(n+1), C(n);
        for (int i=0; i<n; ++i) {
            map[A[i]]++;
            map[B[i]]++;
            common+=(map[A[i]]==2)+(map[B[i]]==2 && B[i]!=A[i]);
            C[i]=common;
        }
        return C;
    }
};