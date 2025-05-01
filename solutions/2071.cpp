// 2071. Maximum Number of Tasks You Can Assign
class Solution {
    public:
        bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength, int k) {
            int n=workers.size();
            multiset<int> strongest(end(workers)-k, end(workers));
            for (int i=k-1; i>=0; --i) {
                auto it=prev(end(strongest));
                if (*it<tasks[i]) {
                    it=strongest.lower_bound(tasks[i]-strength);
                    if (--pills<0 || it==end(strongest))
                        return false;
                }
                strongest.erase(it);
            }
            return true;
        }
    
        int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
            sort(tasks.begin(), tasks.end());
            sort(workers.begin(), workers.end());
    
            int low=0, high=min(tasks.size(), workers.size());
            while (low<high) {
                int mid=(low+high+1)/2;
                if (check(tasks, workers, pills, strength, mid))
                    low=mid;
                else
                    high=mid-1;
            }
            return low;
        }
    };