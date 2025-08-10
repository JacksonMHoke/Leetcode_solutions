// 307. Range Sum Query - Mutable
class NumArray {
public:
    NumArray(vector<int>& nums) {
        segTree.resize(bit_ceil(nums.size())*2);
        n=segTree.size()/2;
        for (int i=0; i<nums.size(); ++i)
            segTree[i+n]=nums[i];
        for (int i=n-1; i>0; --i)
            segTree[i]=segTree[i*2]+segTree[i*2+1];
    }
    
    void update(int index, int val) {
        index+=n;
        segTree[index]=val;
        while (index>1) {
            index/=2;
            segTree[index]=segTree[index*2]+segTree[index*2+1];
        }
    }
    
    int sumRange(int left, int right) {
        left+=n;
        right+=n;
        int sum=segTree[1];
        while (left) {
            if (left%2)
                sum-=segTree[(left/2)*2];
            left/=2;
        }

        while (right) {
            if (right%2==0)
                sum-=segTree[(right/2)*2+1];
            right/=2;
        }
        return sum;
    }
private:
    vector<int> segTree;
    int n;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */