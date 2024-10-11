// 1942. The Number of the Smallest Unoccupied Chair
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int targetTime=times[targetFriend][0];
        sort(times.begin(), times.end());
        set<pair<int, int>> leavingChairs;
        set<int> openChairs;

        for (int i=0; i<times.size(); ++i) {
            openChairs.insert(i);
            while (!leavingChairs.empty() && leavingChairs.begin()->first<=times[i][0]) {
                openChairs.insert(leavingChairs.begin()->second);
                leavingChairs.erase(leavingChairs.begin());
            }

            if (targetTime==times[i][0])
                return *openChairs.begin();

            leavingChairs.insert({times[i][1], *openChairs.begin()});
            openChairs.erase(openChairs.begin());
        }

        return -1;
    }
};