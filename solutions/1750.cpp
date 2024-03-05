// 1750. Minimum Length of String After Deleting Similar Ends
class Solution {
public:
    int minimumLength(string s) {
        int start=0;
        int end=s.length()-1;
        while (start<end) {
            if (s[start]==s[end]) {
                char curr=s[start];
                while (start<s.length() && s[start]==curr)
                    start++;
                while (end>=0 && s[end]==curr)
                    end--;
            } else {
                break;
            }
        }
        return max(0, end-start+1);
    }
};