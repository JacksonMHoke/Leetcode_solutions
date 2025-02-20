// 1980. Find Unique Binary String
class Solution {
    public:
        string findDifferentBinaryString(vector<string>& nums) {
            string rt="";
            for (int i=0; i<nums.size(); ++i)
                rt+=(nums[i][i]=='1') ? '0' : '1';
            return rt;
        }
    };