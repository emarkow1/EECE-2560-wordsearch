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
    Grid();
    Grid(std::string filename);
    char readItem(int i, int j);

    private:
    matrix<char> stored_grid;

};

#endif