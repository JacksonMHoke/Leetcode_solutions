// 38. Count and Say
class Solution {
    public:
        string countAndSay(int n) {
            if (n==1) { return "1"; }
            string rt;
            int i=1;
            int combo=1;
            string prev = countAndSay(n-1);
            
            if (prev=="1") { return "11"; }
            
            while (i<prev.length()) {
                if (prev[i]==prev[i-1]) { ++combo; }
                else {
                    rt+=to_string(combo);
                    combo=1;
                    rt+=prev[i-1];
                }
                
                if (i==prev.length()-1) {
                    rt+=to_string(combo);
                    rt+=prev[i];
                }
                ++i;
            }
            
            return rt;
        }
    };