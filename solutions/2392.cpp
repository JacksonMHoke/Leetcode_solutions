// 2392. Build a Matrix With Conditions
class Solution {
public:
    vector<int> getOrder(int k, vector<vector<int>>& conditions) {
        vector<int> degrees(k);
        vector<vector<int>> adj_list(k);
        vector<int> order;
        for (int i=0; i<conditions.size(); ++i) {
            degrees[conditions[i][1]-1]++;
            adj_list[conditions[i][0]-1].push_back(conditions[i][1]-1);
        }

        queue<int> q;
        for (int i=0; i<k; ++i) {
            if (degrees[i]==0)
                q.push(i);
        }

        while (!q.empty()) {
            int num=q.front();
            q.pop();

            order.push_back(num);

            for (auto child : adj_list[num]) {
                if (--degrees[child]==0)
                    q.push(child);
            }
        }

        return order;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<int> rowOrder=getOrder(k, rowConditions);
        if (rowOrder.size()<k)
            return {};
        vector<int> colOrder=getOrder(k, colConditions);
        if (colOrder.size()<k)
            return {};

        vector<vector<int>> rt(k, vector<int>(k));
        unordered_map<int, int> numToRow;
        for (int i=0; i<k; ++i)
            numToRow[rowOrder[i]]=i;

        for (int j=0; j<k; ++j) {
            int curr=colOrder[j];
            rt[numToRow[curr]][j]=curr+1;
        }
        return rt;
    }
};