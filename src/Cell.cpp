#include "Cell.h"

Cell::Cell() = default;
Cell::Cell(const unsigned int x, const unsigned int y) : x(x), y(y) {}
Cell::Cell(const char type, const unsigned int x, const unsigned int y) : type(type), x(x), y(y) {}
Cell::Cell(const char type) : type(type) {}
Cell::~Cell() {}

char Cell::get_type() const {
    return this->type;
}