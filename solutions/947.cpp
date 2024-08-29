// 947. Most Stones Removed with Same Row or Column
class UnionFind {
public:
    vector<int> unions;

    UnionFind(int numRows) {
        unions.resize(numRows);
        iota(unions.begin(), unions.end(), 0);
    }

    int find(int i) {
        if (unions[i]==i)
            return i;
        unions[i]=find(unions[i]);
        return unions[i];
    }

    void combine(int i, int j) {
        unions[find(i)]=find(unions[j]);
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int r=0, c=0;
        for (auto& coord : stones) {
            r=max(r, coord[0]);
            c=max(c, coord[1]);
        }

        UnionFind uf(r+1);
        vector<int> prevRow(c+1, -1);
        unordered_set<int> rowsWithStones;

        for (auto& coords : stones) {
            int i=coords[0], j=coords[1];
            if (prevRow[j]!=-1) {
                uf.combine(i, prevRow[j]);
            }
            prevRow[j]=i;
            rowsWithStones.insert(i);
        }

        unordered_set<int> groups;
        int remaining=0;
        for (auto row : rowsWithStones) {
            if (!groups.contains(uf.find(row)))
                remaining++;
            groups.insert(uf.find(row));
        }

        return stones.size()-remaining;
    }
};