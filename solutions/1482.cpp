// 1482. Minimum Number of Days to Make m Bouquets
class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=1, end=*max_element(bloomDay.begin(), bloomDay.end())+1;
        int mx=end;
        while (start<end) {
            int mid=(start+end)/2;
            int curr=0, bouq=0;

            for (int i=0; i<bloomDay.size() && bouq<m; ++i) {
                curr=(bloomDay[i]<=mid) ? curr+1 : 0;
                if (curr>=k) {
                    bouq++;
                    curr=0;
                }
            }

            if (bouq>=m)
                end=mid;
            else
                start=mid+1;
        }
        return (start<mx) ? start : -1;
    }
};
