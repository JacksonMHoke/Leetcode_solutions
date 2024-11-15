// 1574. Shortest Subarray to be Removed to Make Array Sorted
class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int rightSorted=1, n=arr.size();
        while (rightSorted<n && arr[n-rightSorted]>=arr[n-1-rightSorted])
            rightSorted++;
        if (rightSorted==n)
            return 0;
        
        int rt=n-rightSorted;
        for (int i=0; i<n; ++i) {
            if (i>0 && arr[i]<arr[i-1])
                break;
            rt=min(rt, (int)(lower_bound(arr.end()-rightSorted, arr.end(), arr[i])-(arr.begin()+i+1)));
        }
        return rt;
    }
};