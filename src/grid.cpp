// EECE 2560 Wordsearch Project
// 1-satbermacmar-2b
// grid.cpp
// authors: Jake Berman, Ethan Markow, Donald Mackinnon, Emile Sater
// Implements Grid class member functions. These functions enable the reading
// of a letter grid from a file, accessing file's characters and dimensions
//

#include "grid.h"
#include "d_except.h"

Grid::Grid(std::string filename) : stored_grid(1, 1)
// Reads Grid dimensions and characters within "filename" and stores them into
// "stored_grid"
{
    ifstream inFile(filename);
    string line;

    if (inFile.is_open())
    {
        // Reads and extracts n, number of rows, from first value in file.
        getline(inFile, line, ' ');
        int n = stoi(line);

        // Reads the m, number of columns, from second value in file.
        getline(inFile, line);
        int m = stoi(line);

        // Resizes internal matrix to the matching rows and columns extracted
        // from file.
        stored_grid = matrix<char>(n, m);

        n = 0;
        
        // Extract characters from file into internal matrix
        while (getline(inFile, line))
        {
            m = 0;
            stringstream ss(line);

            for (string letter; std::getline(ss, letter, ' ');)
            {
                stored_grid[n][m] = letter[0];
                m++;
            }

            n++;
        } // end while

        inFile.close();
    } // end if
    else
    {
        throw fileOpenError(filename);
    } // end else
} // end Grid constructor

char& Grid::at(int row, int column)
// allows a character at a specific row and column to be returned AND modified.
{
    if (row < 0 || row >= stored_grid.rows() ||
        column < 0 || column >= stored_grid.cols())
    {
        throw out_of_range("Grid::at: index out of range");
    }

    return stored_grid[row][column];
} // end at

const char Grid::at(int row, int column) const
// allows a character at a specific row and column to be returned NOT modified.
{
        if (row < 0 || row >= stored_grid.rows() ||
        column < 0 || column >= stored_grid.cols())
    {
        throw out_of_range("Grid::at: index out of range");
    }

    return stored_grid[row][column];
} // end at

int Grid::rows() const
// returns the number of rows in the grid
{
    return this->stored_grid.rows();
} // end rows

int Grid::cols() const
// returns the number of columns in the grid
{
    return this->stored_grid.cols();
} // end cols