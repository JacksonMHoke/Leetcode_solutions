// 2349. Design a Number Container System
class NumberContainers {
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if (nums[index]!=0)
            earliestIndex[nums[index]].erase(index);
        nums[index]=number;
        earliestIndex[number].insert(index);
    }
    
    int find(int number) {
        if (earliestIndex.contains(number) && earliestIndex[number].size()>0)
            return *earliestIndex[number].begin();
        return -1;
    }
private:
    unordered_map<int, set<int>> earliestIndex;
    unordered_map<int, int> nums;
};