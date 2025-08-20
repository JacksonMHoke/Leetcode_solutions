// 699. Falling Squares
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        set<int> points;
        unordered_map<int, int> conversion;
        for (auto& position : positions) {
            points.insert(position[0]);
            points.insert(position[0]+position[1]-1);
        }
        int i=0;
        for (auto num : points)
            conversion[num]=i++;
        for (auto& position : positions) {
            position.push_back(position[1]);
            position[1]=conversion[position[0]+position[1]-1];
            position[0]=conversion[position[0]];
        }

        n=i;
        seg.resize(bit_ceil((unsigned)n)*2);
        lazy.resize(bit_ceil((unsigned)n)*2);
        int mx=0;
        vector<int> rt;
        for (auto& position : positions) {
            int curr=range_max(position[0], position[1], 0, n-1, 1);
            apply(position[0], position[1], curr+position[2], 0, n-1, 1);
            mx=max(mx, curr+position[2]);
            rt.push_back(mx);
        }
        return rt;
    }
private:
    vector<int> lazy;
    vector<int> seg;
    int n;

    void push(int i) {
        if (i*2>=seg.size())
            return;
        lazy[i*2]=max(lazy[i*2], lazy[i]);
        lazy[i*2+1]=max(lazy[i*2+1], lazy[i]);
        seg[i*2]=max(seg[i*2], lazy[i*2]);
        seg[i*2+1]=max(seg[i*2+1], lazy[i*2+1]);
        lazy[i]=INT_MIN;
    }

    void apply(int l, int r, int val, int L, int R, int i) {
        if (R<l || L>r)
            return;
        if (l<=L && R<=r) {
            seg[i]=max(seg[i], val);
            lazy[i]=max(lazy[i], val);
            return;
        }
        push(i);
        int m=(L+R)/2;
        apply(l, min(m, r), val, L, m, i*2);
        apply(max(m+1, l), r, val, m+1, R, i*2+1);
        seg[i]=max(seg[i*2], seg[i*2+1]);
    }

    int range_max(int l, int r, int L, int R, int i) {
        if (l<=L && R<=r)
            return seg[i];
        push(i);
        int m=(L+R)/2, lMax=INT_MIN, rMax=INT_MIN;
        if (l<=m)
            lMax=range_max(l, min(r, m), L, m, i*2);
        if (r>m)
            rMax=range_max(max(l, m+1), r, m+1, R, i*2+1);
        return max(lMax, rMax);
    }
};