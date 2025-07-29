// 2411. Smallest Subarrays With Maximum Bitwise OR
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int right=nums.size()-1;
        vector<int> freqs(32), rt(nums.size());
        for (int i=right; i>=0; --i) {
            int num=nums[i], j=0;
            while (num) {
                freqs[j++]+=num&1;
                num>>=1;
            }
            while (right>0) {
                vector<int> temp(freqs.begin(), freqs.end());
                num=nums[right], j=0;
                bool flag=false;
                while (num) {
                    temp[j]-=num&1;
                    if (temp[j]<=0 && num&1) {
                        flag=true;
                        break;
                    }
                    num>>=1;
                    j++;
                }
                if (flag)
                    break;
                right--;
                freqs=temp;
            }
            rt[i]=max(right-i+1, 1);
        }
        return rt;
    }
};