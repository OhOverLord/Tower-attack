#ifndef CELL_H
#define CELL_H

#include <ncurses.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <sstream>
#include <memory>

using namespace std;

class Cell {
public:
    /**
    * Default constructor for the Cell class.
    */
    Cell();
    /**
     * Constructor for the Cell class.
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     */
    Cell(const unsigned int x, const unsigned int y);
    /**
     * Constructor for the Cell class.
     * @param type The type of the cell.
     * @param x The x-coordinate of the cell.
     * @param y The y-coordinate of the cell.
     */
    Cell(const char type, const unsigned int x, const unsigned int y);
    /**
     * Constructor for the Cell class.
     * @param type The type of the cell.
     */
    Cell(const char type);
    /**
     * Destructor for the Cell class.
     */
    virtual ~Cell();
    /**
     * Get the type of the cell.
     * @return The type of the cell.
     */
    char get_type() const;

    unsigned int x;
    unsigned int y;
    char type;
    int status = -1;
    Cell* before = nullptr;
};


#endif //CELL_H
