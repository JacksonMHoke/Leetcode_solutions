// 752. Open the Lock
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads;
        for (string& end : deadends)
            deads.insert(end);
        
        if (deads.find("0000")!=deads.end())
            return -1;

        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        int lvl=0;
        while (!q.empty()) {
            int sz=q.size();
            for (int i=0; i<sz; ++i) {
                string curr=q.front();
                q.pop();

                if (curr==target)
                    return lvl;

                for (int j=0; j<4; ++j) {
                    char prev=curr[j];
                    if (curr[j]=='9')
                        curr[j]='0';
                    else
                        curr[j]+=1;
                    
                    if (deads.find(curr)==deads.end() && visited.find(curr)==visited.end()) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    
                    curr[j]=prev;
                    if (curr[j]=='0')
                        curr[j]='9';
                    else
                        curr[j]-=1;
                    
                    if (deads.find(curr)==deads.end() && visited.find(curr)==visited.end()) {
                        visited.insert(curr);
                        q.push(curr);
                    }
                    curr[j]=prev;
                }
            }
            lvl++;
        }
        return -1;
    }
};