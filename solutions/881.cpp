// 881. Boats to Save People
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int rt=0, start=0, end=people.size()-1;
        sort(people.begin(), people.end());
        while (start<end) {
            if (people[end]+people[start]<=limit)
                start++;
            end--;
            rt++;
        }
        if (start==end) rt++;
        return rt;
    }
};