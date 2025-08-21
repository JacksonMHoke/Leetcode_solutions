// 715. Range Module
class RangeModule {
public:
    RangeModule() {
        intervals.insert({0, 0});
        intervals.insert({INT_MAX, 0});
    }
    
    void addRange(int left, int right) {
        auto itr=intervals.lower_bound({left, 0});
        int prev=(--itr)->second;
        itr++;
        while (itr!=intervals.end() && itr->first<=right) {
            prev=itr->second;
            itr=intervals.erase(itr);
        }

        intervals.insert({right, prev});
        itr=intervals.find({right, prev});
        removeRedundant(itr);

        intervals.insert({left, 1});
        itr=intervals.find({left, 1});
        removeRedundant(itr);

        itr--;
        removeRedundant(itr);
    }
    
    bool queryRange(int left, int right) {
        auto leftItr=intervals.upper_bound({left, 1});
        leftItr--;
        auto rightItr=intervals.lower_bound({right, 0});
        rightItr--;
        return leftItr->second && (leftItr==rightItr);
    }
    
    void removeRange(int left, int right) {
        auto itr=intervals.lower_bound({left, 0});
        int prev=(--itr)->second;
        itr++;
        while (itr!=intervals.end() && itr->first<=right) {
            prev=itr->second;
            itr=intervals.erase(itr);
        }
        
        intervals.insert({right, prev});
        itr=intervals.find({right, prev});
        removeRedundant(itr);

        intervals.insert({left, 0});

        itr=intervals.find({left, 0});
        removeRedundant(itr);

        itr--;
        removeRedundant(itr);
    }
private:
    set<pair<int, int>> intervals;
    void removeRedundant(set<pair<int, int>>::iterator it) {
        int prev=it->second;
        it++;
        while (it!=intervals.end() && it->second==prev) {
            prev=it->second;
            it=intervals.erase(it);
        }
    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule* obj = new RangeModule();
 * obj->addRange(left,right);
 * bool param_2 = obj->queryRange(left,right);
 * obj->removeRange(left,right);
 */