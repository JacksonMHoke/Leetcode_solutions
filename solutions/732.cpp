// 732. My Calendar III
class Node {
public:
    Node *left, *right;
    int l, r, mx, lazy;
    Node(int lft, int rgt, int val) {
        left=nullptr, right=nullptr;
        l=lft, r=rgt;
        mx=val;
        lazy=0;
    }

    void push() {
        int m=(l+r)/2;
        if (!left) left=new Node(l, m, mx);
        else left->mx+=lazy;
        left->lazy+=lazy;

        if (!right) right=new Node(m+1, r, mx);
        else right->mx+=lazy;
        right->lazy+=lazy;

        lazy=0;
    }

    void range_add(int L, int R, int change) {
        if (R<l || L>r)
            return;
        if (L<=l && r<=R) {
            mx+=change;
            lazy+=change;
            return;
        }
        push();
        left->range_add(L, R, change);
        right->range_add(L, R, change);
        mx=max(left->mx, right->mx);
    }
};

class MyCalendarThree {
public:
    MyCalendarThree() {
        segTree=new Node(0, 1e9+7, 0);
    }
    
    int book(int startTime, int endTime) {
        segTree->range_add(startTime, endTime-1, 1);
        return segTree->mx;
    }
private:
    Node *segTree;
};