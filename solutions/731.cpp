// 731. My Calendar II
class Node {
public:
    Node *left, *right;
    int l, r, lazy, maxBookings;
    Node(int lft, int rgt, int val) {
        l=lft;
        r=rgt;
        maxBookings=val;
        lazy=0;
        left=nullptr;
        right=nullptr;
    }

    void push() {
        if (!left)
            left=new Node(l, l+(r-l)/2, maxBookings);
        else
            left->maxBookings+=lazy;
        left->lazy+=lazy;
        if (!right)
            right=new Node(l+(r-l)/2+1, r, maxBookings);
        else
            right->maxBookings+=lazy;
        right->lazy+=lazy;
        lazy=0;
    }

    void range_update(int L, int R, int change) {
        if (L<=l && r<=R) {
            maxBookings+=change;
            lazy+=change;
            return;
        }
        push();
        int m=l+(r-l)/2;
        if (L<=m)
            left->range_update(L, R, change);
        if (R>m)
            right->range_update(L, R, change);
        maxBookings=max((left)? left->maxBookings: 0, (right)? right->maxBookings: 0);
    }
};

class MyCalendarTwo {
public:
    MyCalendarTwo() {
        segTree=new Node(0, 1e9+7, 0);
    }
    
    bool book(int startTime, int endTime) {
        segTree->range_update(startTime, endTime-1, 1);
        if (segTree->maxBookings>2) {
            segTree->range_update(startTime, endTime-1, -1);
            return false;
        }
        return true;
    }
private:
    Node* segTree;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */