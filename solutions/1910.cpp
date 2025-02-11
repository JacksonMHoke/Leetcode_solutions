// 1910. Remove All Occurrences of a Substring
class Solution {
    public:
        string removeOccurrences(string s, string part) {
            vector<int> longestOverlap(part.length(), -1); // longest shared prefix between part and substring ending at index i(can't be entire substring up until i)
            vector<int> patternIdx;
            int curr=-1, n=s.length(), m=part.length();
            for (int i=1; i<m; ++i) {
                while (part[i]!=part[curr+1] && curr!=-1)
                    curr=longestOverlap[curr];
                curr+=part[i]==part[curr+1];
                longestOverlap[i]=curr;
            }
    
            curr=-1;
            string rt="";
            for (int i=0; i<n; ++i) {
                rt+=s[i];
                while (part[curr+1]!=s[i] && curr!=-1)
                    curr=longestOverlap[curr];
                curr+=part[curr+1]==s[i];
                patternIdx.push_back(curr);
                if (patternIdx.back()>=m-1) {
                    for (int j=0; j<m; ++j) {
                        rt.pop_back();
                        patternIdx.pop_back();
                    }
                    curr=(!patternIdx.empty())? patternIdx.back() : -1;
                }
            }
    
            return rt;
        }
    };