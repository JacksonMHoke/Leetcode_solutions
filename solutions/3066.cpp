// 3066. Minimum Operations to Exceed Threshold Value II
class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());
            int ops=0;
            while (pq.top()<k) {
                long long add=pq.top()*2;
                pq.pop();
                add+=pq.top();
                pq.pop();
                pq.push(add);
                ops++;
            }
            return ops;
        }
    };