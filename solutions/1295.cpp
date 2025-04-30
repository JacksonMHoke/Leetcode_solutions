// 1295. Find Numbers with Even Number of Digits
class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int evens=0;
            for (auto num : nums) {
                int d=0;
                while (num) {
                    num/=10;
                    d++;
                }
                evens+=d%2==0;
            }
            return evens;
        }
    };