// 769. Max Chunks To Make Sorted
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int mask=0, curr=0, chunks=0;
        for (int i=0; i<arr.size(); ++i) {
            curr|=1<<arr[i];
            mask|=1<<i;
            if ((curr&mask)==mask) {
                mask=0;
                chunks++;
            }
        }
        return chunks;
    }
};