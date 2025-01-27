// 1462. Course Schedule IV
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        vector<unordered_set<int>> isPreq(numCourses);
        vector<int> inDegree(numCourses);
        vector<vector<int>> adjList(numCourses);
        vector<bool> rt;
        for (int i=0; i<preq.size(); ++i) {
            inDegree[preq[i][1]]++;
            adjList[preq[i][0]].push_back(preq[i][1]);
        }

        queue<int> zeroDeg;
        for (int i=0; i<numCourses; ++i)
            if (inDegree[i]==0)
                zeroDeg.push(i);
        
        while (!zeroDeg.empty()) {
            int i=zeroDeg.front();
            zeroDeg.pop();

            for (auto nei : adjList[i]) {
                isPreq[nei].insert(isPreq[i].begin(), isPreq[i].end());
                isPreq[nei].insert(i);
                inDegree[nei]--;
                if (inDegree[nei]==0)
                    zeroDeg.push(nei);
            }
        }

        for (int i=0; i<queries.size(); ++i)
            rt.push_back(isPreq[queries[i][1]].contains(queries[i][0]));
        return rt;
    }
};