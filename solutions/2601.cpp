// 2601. Prime Subtraction Operation
class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<bool> sieve(1001, true);
        for (int i=2; i<32; ++i) {
            if (!sieve[i])
                continue;
            for (int j=i*i; j<=1000; j+=i) {
                sieve[j]=false;
            }
        }
        vector<int> primes;
        for (int i=2; i<sieve.size(); ++i)
            if (sieve[i])
                primes.push_back(i);
        
        for (int i=nums.size()-2; i>=0; --i) {
            if (nums[i]>=nums[i+1]) {
                auto it=upper_bound(primes.begin(), primes.end(), nums[i]-nums[i+1]);
                if (it==primes.end() || nums[i]-*it<=0)
                    return false;
                nums[i]-=*it;
            }
        }

        return true;
    }
};