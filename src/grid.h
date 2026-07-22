#ifndef GRID_H
#define GRID_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "d_matrix.h"
using namespace std;
class Grid
{
    public:
    Grid(std::string filename);
    char& at(int row, int column);
    const char at(int row, int column) const;
    int rows()const;
    int cols() const;

    private:
    matrix<char> stored_grid;
};

#endif