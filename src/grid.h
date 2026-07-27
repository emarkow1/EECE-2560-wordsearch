// EECE 2560 Wordsearch Project
// 1-satbermacmar-2a
// grid.h
//
// This file declares the Grid class.
//

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
// Stores the letters found in "filename" wordsearch in a matrix. functions
// within this class allow access to obtain and utilize these characters
{
    public:
    Grid(std::string filename);
    // using dimensions and characters given in "filename" to create a grid

    char& at(int row, int column);
    // returns a modifiable reference of a specific character (using row and
    // column to find).

    const char at(int row, int column) const;
    // returns a specific character (unmodifiable using row and column to find)

    int rows()const;
    // returns the number of rows in the grid
    
    int cols() const;
    // returns the number of columns in the grid

    private:
    matrix<char> stored_grid;
    // writes/stores the characters in the grid.
}; // end Grid class

#endif // GRID_H