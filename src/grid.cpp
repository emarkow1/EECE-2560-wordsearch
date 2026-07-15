// grid.cpp
// Defines member functions of grid class

#include "grid.h"

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

const char Grid::readLetter(const int& row, const int& column)
{
    return this->stored_grid[row][column];
}

const int Grid::rows()
{
    return this->stored_grid.rows();
}

const int Grid::cols()
{
    return this->stored_grid.cols();
}