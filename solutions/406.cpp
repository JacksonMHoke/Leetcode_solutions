// 406. Queue Reconstruction by Height
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0]<rhs[0]; });
        vector<vector<int>> reconstructed(people.size());
        
        segTree.resize(bit_ceil(people.size())*2);
        n=segTree.size()/2;
        for (int i=0; i<people.size(); ++i)
            segTree[i+n]=1;
        for (int i=n-1; i>0; --i)
            segTree[i]=segTree[i*2]+segTree[i*2+1];

        vector<int> toUpdate;
        for (int i=0; i<people.size(); ++i) {
            if (i>0 && people[i][0]!=people[i-1][0]) {
                for (; !toUpdate.empty(); toUpdate.pop_back())
                    update(toUpdate.back(), 0);
            }
            int idx=findIdx(people[i][1]+1);
            toUpdate.push_back(idx);
            reconstructed[idx]=people[i];
        }
        return reconstructed;
    }

private:
    vector<int> segTree;
    int n;

    void update(int i, int val) {
        i+=n;
        segTree[i]=val;
        while (i>1) {
            i/=2;
            segTree[i]=segTree[i*2]+segTree[i*2+1];
        }
    }

    int findIdx(int sum) {
        int i=1;
        while (i*2<segTree.size()) {
            if (segTree[i*2]>=sum)
                i=i*2;
            else {
                sum-=segTree[i*2];
                i=i*2+1;
            }
        }
        return i-n;
    }
};