// 2698. Find the Punishment Number of an Integer
class Solution {
    public:
        bool bottomUpSlow(string num, int n) {
            vector<unordered_set<int>> dp(num.length()+1);
            dp.back().insert(0);
            for (int i=num.length()-1; i>=0; --i) {
                int curr=0;
                for (int j=i; j<num.length(); ++j) {
                    curr=curr*10+(num[j]-'0');
                    if (curr>n)
                        break;
                    for (auto val : dp[j+1]) {
                        dp[i].insert(val+curr);
                        if (i==0 && val+curr==n)
                            return true;
                    }
                }
            }
            return false;
        }
    
        bool isPunishmentNumber(string& num, int n, int i) {
            if (i>=num.length() | | n<0)
                return n==0;
            int curr=0;
            for (int j=i; j<num.length() && curr<=n; ++j) {
                curr=curr*10+(num[j]-'0');
                if (isPunishmentNumber(num, n-curr, j+1))
                    return true;
            }
            return false;
        }
    
        int punishmentNumber(int n) {
            int rt=0;
            for (int i=1; i<=n; ++i) {
                string nStr=to_string(i*i);
                rt+=i*i*isPunishmentNumber(nStr, i, 0);
            }
            return rt;
        }
    };