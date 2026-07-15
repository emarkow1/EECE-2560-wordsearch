#ifndef GRID_H
#define GRID_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#include "d_matrix.h"

class Grid
{
    public:
    Grid(std::string filename);
    const char readLetter(const int& row, const int& column);
    const int rows();
    const int cols();

    private:
    matrix<char> stored_grid;
};

#endif