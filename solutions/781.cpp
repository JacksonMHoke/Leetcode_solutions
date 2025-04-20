// 781. Rabbits in Forest
class Solution {
    public:
        int numRabbits(vector<int>& answers) {
            vector<int> freqs(1001);
            for (auto ans : answers)
                freqs[ans]++;
            int pop=0;
            for (int i=0; i<=1000; ++i)
                pop+=(freqs[i]+i)/(i+1)*(i+1);
            return pop;
        }
    };