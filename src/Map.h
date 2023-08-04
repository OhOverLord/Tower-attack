#ifndef MAP_H
#define MAP_H

#include <queue>
#include <unordered_set>
#include "Cell.h"

class Map {
public:
    /**
    * Default constructor for the Map class.
    **/
    Map() = default;
    /**
     * Constructor to initialize the Map with the given width and height.
     * @param width The width of the Map.
     * @param height The height of the Map.
     */
    Map(unsigned int width, unsigned int height);

    /**
     * Destructor for the Map class.
     */
    ~Map();

    /**
     * Set the starting position on the Map.
     * @param x The x-coordinate of the starting position.
     * @param y The y-coordinate of the starting position.
     */
    void set_start(const unsigned int x, const unsigned int y);

    /**
     * Set the ending position on the Map.
     * @param x The x-coordinate of the ending position.
     * @param y The y-coordinate of the ending position.
     */
    void set_end(const unsigned int x, const unsigned int y);

    /**
     * Set the hp value for the Map.
     * @param hp The hp value to set.
     */
    void set_hp(const int hp);

    /**
     * Find the path for soldiers on the Map.
     */
    void find_soldiers_path();

    /**
     * Ignore walls and find a path on the Map.
     */
    void ignore_walls_path();

    /**
     * Get the height of the Map.
     * @return The height of the Map.
     */
    unsigned int get_height();

    /**
     * Get the width of the Map.
     * @return The width of the Map.
     */
    unsigned int get_width();

    /**
     * The map grid representing the cells of the Map.
     */
    vector<vector<Cell *>> map;

    /**
     * The path for the soldiers on the Map.
     */
    vector<Cell *> soldiers_path;

private:
    /**
     * The width of the Map.
     */
    unsigned int width = 0;

    /**
     * The height of the Map.
     */
    unsigned int height = 0;

    /**
     * The x-coordinate of the starting position.
     */
    unsigned int s_x = 0;

    /**
     * The y-coordinate of the starting position.
     */
    unsigned int s_y = 0;

    /**
     * The x-coordinate of the ending position.
     */
    unsigned int e_x = 0;

    /**
     * The y-coordinate of the ending position.
     */
    unsigned int e_y = 0;

    /**
     * The hp value of the Map.
     */
    int hp;
};

#endif //MAP_H
