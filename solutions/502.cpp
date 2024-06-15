// 502. IPO
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=profits.size();
        vector<pair<int, int>> cp;
        for (int i=0; i<n; ++i)
            cp.push_back({capital[i], profits[i]});
        sort(cp.begin(), cp.end());

        priority_queue<int> valid_profits;

        int i=0;
        while (k>0) {
            while (i<n && cp[i].first<=w)
                valid_profits.push(cp[i++].second);
            
            if (valid_profits.empty())
                return w;
            w+=valid_profits.top();
            valid_profits.pop();
            k--;
        }
        return w;
    }
};