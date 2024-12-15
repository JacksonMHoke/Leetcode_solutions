// 1792. Maximum Average Pass Ratio
class Solution {
public:
    double findIncrease(double num, double denom) {
        return (denom-num)/(denom*(denom+1));
    }
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<double, int>> increase;
        for (int i=0; i<classes.size(); ++i)
            increase.push({findIncrease(classes[i][0], classes[i][1]), i});
        while (extraStudents>0) {
            auto [inc, i]=increase.top();
            increase.pop();
            double secondBestIncrease=(!increase.empty()) ? increase.top().first : 0;
            while (extraStudents>0 && findIncrease(classes[i][0], classes[i][1])>=secondBestIncrease) {
                classes[i][0]++;
                classes[i][1]++;
                extraStudents--;
            }
            increase.push({findIncrease(classes[i][0], classes[i][1]), i});
        }
        double avg=0;
        for (int i=0; i<classes.size(); ++i)
            avg+=(double)classes[i][0]/(double)classes[i][1];
        return avg/classes.size();
    }
};