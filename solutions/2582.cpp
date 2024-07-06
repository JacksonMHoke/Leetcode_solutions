// 2582. Pass the Pillow
class Solution {
public:
    int passThePillow(int n, int time) {
        return n - abs(n - 1 - time % (n * 2 - 2));
    }
};