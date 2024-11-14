// 2064. Minimized Maximum of Products Distributed to Any Store
class Solution {
public:
    bool check(vector<int>& quantities, int n, int x) {
        for (auto quantity : quantities)
            n-=(quantity+x-1)/x;
        return n>=0;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int start=1, end=100000;
        while (start<end) {
            int mid=(start+end)/2;
            if (check(quantities, n, mid))
                end=mid;
            else
                start=mid+1;
        }
        return start;
    }
};