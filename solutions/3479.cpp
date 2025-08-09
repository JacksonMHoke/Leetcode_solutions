// 3479. Fruits Into Baskets III
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        segTree.resize(1<<((int)ceil(log2(fruits.size()))+1));
        n=1<<((int)ceil(log2(fruits.size())));
        for (int i=0; i<baskets.size(); ++i)
            update(i, baskets[i]);

        int placed=0;
        for (auto fruit : fruits) {
            int i=leftmost(fruit);
            if (i==-1)
                continue;
            placed++;
            update(i, 0);
        }
        return fruits.size()-placed;
    }
private:
    vector<int> segTree;
    int n;

    int leftmost(int numFruits, int i=1) {
        if (segTree[i]<numFruits)
            return -1;
        if (i*2>=segTree.size())
            return i-n;
        if (segTree[i*2]>=numFruits)
            return leftmost(numFruits, i*2);
        if (segTree[i*2+1]>=numFruits)
            return leftmost(numFruits, i*2+1);
        return -1;
    }

    void update(int i, int newCap) {
        i+=n;
        segTree[i]=newCap;
        i/=2;
        while (i) {
            segTree[i]=max(segTree[i*2], segTree[i*2+1]);
            i/=2;
        }
    }
};