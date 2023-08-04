#ifndef ROAD_H
#define ROAD_H

#include "Cell.h"
#include "Soldier.h"

class Road : public Cell {
public:
    /**
     * Constructs a Road object with the specified character, x-coordinate, and y-coordinate.
     * @param character The character representation of the road.
     * @param x The x-coordinate of the road.
     * @param y The y-coordinate of the road.
     */
    Road(const char character, const unsigned int x, const unsigned int y);
};

#endif //ROAD_H
