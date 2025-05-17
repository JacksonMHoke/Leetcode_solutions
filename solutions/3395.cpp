// iterate over the possible middle unique mode numbers
// there cannot be unique modes of length 1
// numbers not necessarily in sorted order
// there are a limited number of possible setups because the subsequence limit is 5
// if the unique mode if 2 then the subsequence must be formed with either a abbaa or aabba
// in general if we are considering a unique mode with the number x at index 2, we can find the number of possible
// subsequences with it in the middle by finding the remaining number of b's in the array and also the remaining number of items before and after it
// To calculate the number of subsequences have this element in the middle, we need to take into account 2 cases. The case where the other side of the
// subsequence has a b and the case where the other side of the subsequence doesn't have a b. If the other side has a b, we just add the number of ways we can
// choose the elements on the left side of the array. If other other side doesn't have a b, we have to multiply the number of ways we can pick the right elements times
// the number of ways we can pick the left side with at least 1 b in it.
// We also have to consider the fact that if we only pick 2 b's we cannot pick a duplicate number, if we ever pick 3 b's it won't matter.
// 
class Solution {
    public:
        int subsequencesWithMiddleMode(vector<int>& nums) {
            return 0;
        }
    };