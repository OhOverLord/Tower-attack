#ifndef WALL_H
#define WALL_H

#include "Cell.h"

class Wall : public Cell {
public:
    /**
     * Wall constructor.
     * @param[in] character The character representing the wall.
     * @param[in] x The x-coordinate of the wall.
     * @param[in] y The y-coordinate of the wall.
     */
    Wall(const char character, const unsigned int x, const unsigned int y);
};

#endif //WALL_H
