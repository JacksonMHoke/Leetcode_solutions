// 1552. Magnetic Force Between Two Balls
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int start=0, end=position.back();
        
        while (start<end) {
            int mid=(start+end+1)/2, prev=position[0], balls=1;
            for (int i=0; i<position.size() && balls<m; ++i) {
                if (position[i]-prev>=mid) {
                    prev=position[i];
                    balls++;
                }
            }

            if (balls>=m)
                start=mid;
            else
                end=mid-1;
        }
        return start;
    }
};