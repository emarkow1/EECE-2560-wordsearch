// grid.cpp
// Defines member functions of grid class

#include "grid.h"

// Constructor for grid class
// Accepts the name of a file as a string and fills out a matrix with chars
Grid::Grid(std::string filename) : stored_grid(1, 1)
{
    std::ifstream inFile(filename);
    std::string line;

    if (inFile.is_open())
    {
        // Extract n (rows) and m (columns) from the first line of a file
        std::getline(inFile, line, ' ');
        int n = stoi(line);

        std::getline(inFile, line);
        int m = stoi(line);

        stored_grid = matrix<char>(n, m);

        n = 0;
        
        // Extract characters from file into internal matrix
        while (std::getline(inFile, line))
        {
            m = 0;
            std::stringstream ss(line);
            for (std::string letter; std::getline(ss, letter, ' ');)
            {
                stored_grid[n][m] = letter[0];
                m++;
            }
            n++;
        }
        inFile.close();
    } else {
        std::cerr << "Error Opening File " << filename << std::endl;
    }
}

char& Grid::at(int row, int column)
{
    if (row < 0 || row >= stored_grid.rows() ||
        column < 0 || column >= stored_grid.cols())
    {
        throw std::out_of_range("Grid::at: index out of range");
    }
    return stored_grid[row][column];
}

// Reads char from a specified location on the grid
const char Grid::at(int row, int column) const
{
        if (row < 0 || row >= stored_grid.rows() ||
        column < 0 || column >= stored_grid.cols())
    {
        throw std::out_of_range("Grid::at: index out of range");
    }
    return stored_grid[row][column];
}

const int Grid::rows()
{
    return this->stored_grid.rows();
}

const int Grid::cols()
{
    return this->stored_grid.cols();
}