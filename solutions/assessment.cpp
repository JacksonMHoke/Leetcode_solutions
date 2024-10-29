#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <memory>

using namespace std;

/*
 * Complete the 'escape_castle' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER rows
 *  2. INTEGER columns
 *  3. 2D_INTEGER_ARRAY walls
 *  4. INTEGER_ARRAY escape_point
 */
 
class Location {
public:
    Location(int _x, int _y) : x(_x), y(_y), explored(false) {}

    virtual ~Location() = default;

    pair<int, int> getLocation() {
        return {x, y};
    }

    bool isExplored() {
        return explored; 
    }

    void explore() {
        explored = true;
    }

    virtual bool isExit() {
        return false;
    }

    virtual bool isWalkable()=0;
private:
    int x;
    int y;
    bool explored;
};

class Wall : public Location {
public:
    Wall(int _x, int _y) : Location(_x, _y) {}

    bool isWalkable() override {
        return false;
    }
};

class Exit : public Location {
public:
    Exit(int _x, int _y) : Location(_x, _y) {}

    bool isWalkable() override {
        return true;
    }

    bool isExit() override {
        return true;
    }
};

class EmptyLocation : public Location {
public:
    EmptyLocation(int _x, int _y) : Location(_x, _y) {}

    bool isWalkable() override {
        return true;
    }
};

class Castle {
public:
    Castle(int _rows, int _cols) : rows(_rows), cols(_cols) {
        for (int i = 0; i < rows; ++i) {
            grid.push_back(vector<unique_ptr<Location>>());
            for (int j = 0; j < cols; ++j) {
                grid[i].push_back(make_unique<EmptyLocation>(i, j));
            }
        }
    }

    Location* get(int _i, int _j) {
        return grid[_i][_j].get();
    }

    void placeWall(int _i, int _j) {
        if (_i<0 || _i>=rows || _j<0 || _j>=cols)
            return;
        grid[_i][_j] = make_unique<Wall>(_i, _j);
    }

    void placeExit(int _i, int _j) {
        if (_i<0 || _i>=rows || _j<0 || _j>=cols)
            return;
        grid[_i][_j] = make_unique<Exit>(_i, _j);
    }

private:
    int rows;
    int cols;
    vector<vector<unique_ptr<Location>>> grid;
};

int escape_castle(int rows, int columns, vector<vector<int>> walls, vector<int> escape_point) {
    Castle castle(rows, columns);
    for (auto& wall : walls)
        castle.placeWall(wall[0], wall[1]);
    castle.placeExit(escape_point[0], escape_point[1]);

    vector<vector<int>> dirs{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    queue<pair<int, int>> bfs;
    bfs.push({0, 0});
    int dist = 0;
    while (!bfs.empty()) {
        int sz = bfs.size();
        for (int i = 0; i < sz; ++i) {
            auto [x, y] = bfs.front();
            bfs.pop();

            for (auto& dir : dirs) {
                int nx = x + dir[0];
                int ny = y + dir[1];

                if (nx < 0 || nx >= rows || ny < 0 || ny >= columns)
                    continue;
                
                Location* next = castle.get(nx, ny);
                if (next->isExit())
                    return dist+1;
                else if (next->isWalkable() && !next->isExplored()) {
                    bfs.push({nx, ny});
                    next->explore();
                }
            }
        }
        dist++;
    }

    return 0;
}

int main () {
    int rows=3, cols=5;
    vector<vector<int>> walls{{0, 1}, {1, 1}, {1, 3}, {2, 3}};
    vector<int> escape_point{2, 4};
    cout << escape_castle(rows, cols, walls, escape_point) << endl;
}