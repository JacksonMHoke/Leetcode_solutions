// 2530. Maximal Score After Applying K Operations
class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        long long rt=0;
        while (k--) {
            int num=pq.top();
            pq.pop();
            pq.push(num/3+(num%3!=0));
            rt+=num;
        }
        return rt;
    }
};