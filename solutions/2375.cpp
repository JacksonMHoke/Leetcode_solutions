// 2375. Construct Smallest Number From DI String
class Solution {
    public:
        bool backtrack(vector<int>& used, string& pattern, string& curr, int i, bool inc) {
            if (i>pattern.length())
                return true;
            char prev=(!curr.empty())? curr.back(): '0';
            for (int j=(inc==1)? prev+1: '1'; j<='9' && (j<prev | | inc); ++j) {
                if (used[j-'1'])
                    continue;
                curr+=j, used[j-'1']=true;
                if (curr.length()==pattern.length()+1 | | backtrack(used, pattern, curr, i+1, pattern[i]=='I'))
                    return true;
                curr.pop_back(), used[j-'1']=false;
            }
            return false;
        }
    
        string smallestNumber(string pattern) {
            vector<int> used(9);
            string curr;
            backtrack(used, pattern, curr, 0, true);
            return curr;
        }
    };