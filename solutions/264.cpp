// 264. Ugly Number II
class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n];
        arr[0] = 1;
        int index2 = 0;
        int index3 = 0;
        int index5 = 0;
        for (int i = 1; i < n; ++i) {
            arr[i] = min(arr[index2]*2, min(arr[index3]*3, arr[index5]*5));
            if (arr[i] == arr[index2]*2) {
                index2++;
            }
            if (arr[i] == arr[index3]*3) {
                index3++;
            }
            if (arr[i] == arr[index5]*5) {
                index5++;
            }
        }
        return arr[n-1];
    }
};