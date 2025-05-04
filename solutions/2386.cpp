// 2386. Find the K-Sum of an Array
class Solution {
    public:
        long long minSum, maxSum;
        int check(vector<int>& nums, int k, long long sum) {
            multiset<long long> sums{maxSum};
    
            for (int i=0; i<nums.size(); ++i) {
                vector<long long> toAdd;
                for (auto it=sums.rbegin(); it!=sums.rend(); ++it) {
                    long long s=*it;
                    if (s-nums[i]<sum)
                        break;
                    toAdd.push_back(s-nums[i]);
                }
                for (auto s : toAdd)
                    sums.insert(s);
                if (sums.size()>k)
                    return (sums.size()-sums.count(sum)<=k)?1:2;
            }
            if (sums.size()==k || sums.size()>k && sums.size()-sums.count(sum)<=k)
                return 1;
            return 0;
        }
        long long kSum(vector<int>& nums, int k) {
            minSum=0, maxSum=0;
            for (int i=0; i<nums.size(); ++i) {
                if (nums[i]<0) {
                    minSum+=nums[i];
                    nums[i]*=-1;
                } else if (nums[i]>0) {
                    maxSum+=nums[i];
                }
            }
            long long low=minSum, high=maxSum, res=0;
            while (low<=high) {
                long long mid=low+(high-low)/2;
                int c=check(nums, k, mid);
                if (c==1) {
                    res=mid;
                    low=mid+1;
                } else if (c==2) {
                    low=mid+1;
                } else {
                    high=mid-1;
                }
            }
            return res;
        }
    };
    
    // set of sums check starting from smallest possible sum. binary search on sums