#include <vector>
#include <iostream>
#include <string>
#include <queue>

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
    Location(int _x, int _y) {
        x=_x;
        y=_y;
    };
    int x;
    int y;

    virtual ~Location() {}
};

class Wall : public Location {
public:
    Wall(int _x, int _y) : Location(_x, _y) {}
};

class Exit : public Location {
public:
    Exit(int _x, int _y) : Location(_x, _y) {}
};

class Explored : public Location {
public:
    Explored(int _x, int _y) : Location(_x, _y) {}
};

class Adventurer {
public:
    int x;
    int y;
    Adventurer(int _x, int _y) {
        x=_x;
        y=_y;
    }
    
    int interact(Location* loc) {
        if (typeid(*loc) == typeid(Wall) || typeid(*loc) == typeid(Explored))
            return -1;
        if (typeid(*loc) == typeid(Exit))
            return 1;
        return 0;
    }
    
    void move(int _x, int _y) {
        x=_x;
        y=_y;
    }
};

class Castle {
public:
    vector<vector<Location*>> grid;
    int rows;
    int cols;
    Castle(int _rows, int _cols) {
        rows=_rows;
        cols=_cols;
        grid=vector<vector<Location*>>(rows, vector<Location*>(cols));
        
        for (int i=0; i<rows; ++i) {
            for (int j=0; j<cols; ++j) {
                grid[i][j] = new Location(i, j);
            }
        }
    }
    
    void set(int _x, int _y, Location* to) {
        if (_x < 0 || _x >= rows || _y < 0 || _y >= cols)
            return;
        delete grid[_x][_y];
        grid[_x][_y] = to;
    }
    
    Location* get(int _x, int _y) {
        if (_x < 0 || _x >= rows || _y < 0 || _y >= cols)
            return nullptr;
        return grid[_x][_y];
    }
};

vector<int> escape_castle(int rows, int columns, vector<vector<int>> walls, vector<int> escape_point) {
    if (escape_point[0] == 0 && escape_point[1] == 0)
        return {0};
    Castle castle = Castle(rows, columns);
    
    for (auto& wall : walls)
        castle.set(wall[0], wall[1], new Wall(wall[0], wall[1]));
    castle.set(escape_point[0], escape_point[1], new Exit(escape_point[0], escape_point[1]));
    Adventurer adventurer = Adventurer(0, 0);
    
    vector<int> dirs{0, 1, 0, -1, 0};
    queue<Location*> bfs;
    bfs.push(castle.get(0, 0));
    int dist = 0;
    while (!bfs.empty()) {
        int sz = bfs.size();
        for (int i=0; i<sz; ++i) {
            Location* curr = bfs.front();
            bfs.pop();
            
            for (int j=0; j<dirs.size()-1; ++j) {
                if (curr->x + dirs[j] < 0 || curr->x + dirs[j] >= rows || curr->y + dirs[j + 1] < 0 || curr->y + dirs[j + 1] >= columns)
                    continue;
                Location* interactWith = castle.get(curr->x + dirs[j], curr->y + dirs[j + 1]);
                int interaction = adventurer.interact(interactWith);
                cout << interaction << " " << curr->x + dirs[j] << " " << curr->y + dirs[j + 1] << endl;
                if (interaction == 1)
                    return {dist+1};
                if (interaction == 0) {
                    castle.set(curr->x + dirs[j], curr->y + dirs[j + 1], new Explored(curr->x + dirs[j], curr->y + dirs[j + 1]));
                    bfs.push(castle.get(curr->x + dirs[j], curr->y + dirs[j + 1]));
                }
            }
        }
        
        dist++;
    }
    
    return {-1};
}

int main () {
    int rows=2, cols=2;
    vector<vector<int>> walls;
    vector<int> escape_point{1, 1};
    Location* wall = new Wall(1, 2);
    // cout << (typeid((*wall))==typeid(Wall)) << endl;
    cout << escape_castle(rows, cols, walls, escape_point)[0] << endl;
}