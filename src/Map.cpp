#include "Map.h"

Map::Map(unsigned int width, unsigned int height) : width(width), height(height) {
    map.resize(height);
    for (auto & row : map) {
        row.resize(width);
    }
}

Map::~Map() = default;

unsigned int Map::get_height() {
    return this->height;
}

unsigned int Map::get_width() {
    return this->width;
}

void Map::set_start(const unsigned int x, const unsigned int y) {
    s_x = x;
    s_y = y;
}

void Map::set_end(const unsigned int x, const unsigned int y) {
    e_x = x;
    e_y = y;
}

void Map::find_soldiers_path() {
    soldiers_path.clear();

    queue<Cell*> queue;
    unordered_set<Cell*> visited;

    if (s_x >= width || s_y >= height || e_x >= width || e_y >= height) {
        cout << "Invalid start or end position." << endl;
        return;
    }

    Cell* startCell = map[s_y][s_x];

    startCell->status = 0;

    queue.push(startCell);
    visited.insert(startCell);

    while (!queue.empty()) {
        Cell* currentCell = queue.front();
        queue.pop();

        int currentX = currentCell->x;
        int currentY = currentCell->y;

        if (currentX == e_x && currentY == e_y) {
            break;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; ++i) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                Cell* neighborCell = map[newY][newX];

                if (neighborCell && visited.find(neighborCell) == visited.end() && neighborCell->status == -1
                                 && neighborCell->type != '#' && neighborCell->type != 'I') {
                    neighborCell->status = 0;
                    neighborCell->before = currentCell;
                    queue.push(neighborCell);
                    visited.insert(neighborCell);
                }
            }
        }

        currentCell->status = 1;
    }

    if (e_x >= width || e_y >= height) {
        cout << "Invalid end position." << endl;
        return;
    }

    Cell* endCell = map[e_y][e_x];

    while (endCell) {
        soldiers_path.push_back(endCell);
        endCell = endCell->before;
    }
}


void Map::ignore_walls_path() {
    soldiers_path.clear();

    queue<Cell*> queue;
    unordered_set<Cell*> visited;

    if (s_x >= width || s_y >= height || e_x >= width || e_y >= height) {
        cout << "Invalid start or end position." << endl;
        return;
    }

    Cell* startCell = map[s_y][s_x];

    startCell->status = 0;

    queue.push(startCell);
    visited.insert(startCell);

    while (!queue.empty()) {
        Cell* currentCell = queue.front();
        queue.pop();

        int currentX = currentCell->x;
        int currentY = currentCell->y;

        if (currentX == e_x && currentY == e_y) {
            break;
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {-1, 0, 1, 0};

        for (int i = 0; i < 4; ++i) {
            int newX = currentX + dx[i];
            int newY = currentY + dy[i];

            if (newX >= 0 && newX < width && newY >= 0 && newY < height) {
                Cell* neighborCell = map[newY][newX];

                if (neighborCell && visited.find(neighborCell) == visited.end() && neighborCell->status == -1) {
                    neighborCell->status = 0;
                    neighborCell->before = currentCell;
                    queue.push(neighborCell);
                    visited.insert(neighborCell);
                }
            }
        }

        currentCell->status = 1;
    }

    if (e_x >= width || e_y >= height) {
        cout << "Invalid end position." << endl;
        return;
    }

    Cell* endCell = map[e_y][e_x];

    while (endCell) {
        soldiers_path.push_back(endCell);
        endCell = endCell->before;
    }
}