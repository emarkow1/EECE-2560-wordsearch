// EECE 2560 Wordsearch Project
// 1-satbermacmar-2a
// main.cpp
//
// This file defines the findMatches() and search() fnctions and contains the
// implementation of the "dictionary" class member functions and performs the
// word search using all defined functions within the project.
//

#include "dictionary.h"
#include "grid.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

void findMatches(const Dictionary& dict, const Grid& g);
// searches "g" in all different directions to find words (atleast 5 characters
// long). Uses dict in order to use binary search to look up and write
// different matches.

void search();
// loads and sorts the dictionary in the inputted "filename" grid. Finds all
// the matching words and prints them out. 

int main()
// starts the program
{
    search();

    return 0;
}
// BELOW IS THE HARDCODED/OUTADED MAIN FUNCTION
// int main() {

//     Dictionary dict;
//     //dict.readWords("Dictionary.txt");
//     dict.readWords("dictionary-sorted.txt");
//     dict.sortStandard("dict_sort_test.txt");
//     //dict.sortWords("dict_sort_test.txt");
//     //cout << dict << endl;
//     cout << dict.lookupWord("Birthdate") << endl;
//     Grid g("input15.txt");
//     findMatches(dict, g);

//     search();

//     return 0;
// }


// Defines the findMatches function that intakes the dictionary and letter grid
// and searches for all possible words in the grid based on words in the
// dictionary. Writes results into output.txt

void findMatches(const Dictionary& dict, const Grid& g)
// Creates index to keep track of steps and opens output.txt file
{
    int index;
    ofstream fout;
    fout.open("output.txt");

    if (!fout)
    {
        throw "File was not opened successfully";
    }

    // Writes and formats column headers for results in output.txt
    fout << left << setw(20) << "Word"
         << setw(20) << "start point (i, j)"
         << "found_index" << endl;

    // For loop to iterate through each letter in a column
    // (i.e moves iterator from top to bottom)
    for (int i = 0; i < g.rows(); i++)
    {
        // For loop to iterate through each letter in a row 
        // (i.e moves iterator from left to right)
        for (int j = 0; j < g.cols(); j++)
        {
            string word;

            // Algorithm to search for words in the south direction
            for (int k = 0; k < g.rows(); k++)
            {
                int loopAround = (i + k) % g.rows();
                word += g.at(loopAround, j);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", " +
                            to_string(j) + ")";
                        fout << left << setw(20) << word
                             << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end south search

            // Algorithm to search for words in the north direction
            word = "";
    
            for (int k = 0; k < g.rows(); k++)
            {
                int loopAround = (i - k + g.rows()) % g.rows();
                word += g.at(loopAround, j);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", "
                            + to_string(j) + ")";
                        fout << left << setw(20) << word
                            << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end north search

            // Algorithm to search for words in the east direction
            word = "";

            for (int k = 0; k < g.cols(); k++)
            {
                int loopAround = (j + k) % g.cols();
                word += g.at(i, loopAround);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", " +
                            to_string(j) + ")";
                        fout << left << setw(20) << word
                        << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end east search

            // Algorithm to search for words in the west directon
            word = "";

            for (int k = 0; k < g.cols(); k++)
            {
                int loopAround = (j - k + g.cols()) % g.cols();
                word += g.at(i, loopAround);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", "
                            + to_string(j) + ")";
                        fout << left << setw(20) << word
                             << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end west search

            // Algorithm for searching for words in the southeast direction
            word = "";

            for (int k = 0; k < g.rows(); k++)
            {
                int loopAroundr = ((i + k) % g.rows());
                int loopAroundc = ((j + k) % g.cols());
                word += g.at(loopAroundr, loopAroundc);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", "
                            + to_string(j) + ")";
                        fout << left << setw(20) << word
                             << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end southeast search

            // Algorithm for searching for words in the southwest direction
            word = "";

            for (int k = 0; k < g.rows(); k++)
            {
                int loopAroundr = ((i + k) % g.rows());
                int loopAroundc = ((j - k + g.cols()) % g.cols());
                word += g.at(loopAroundr, loopAroundc);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", "
                            + to_string(j) + ")";
                        fout << left << setw(20) << word
                             << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end southwest search

            // Algorithm for searching for words in the northwest direction
            word = "";

            for (int k = 0; k < g.rows(); k++)
            {
                int loopAroundr = ((i - k + g.rows()) % g.rows());
                int loopAroundc = ((j - k + g.cols()) % g.cols());
                word += g.at(loopAroundr, loopAroundc);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", "
                        + to_string(j) + ")";
                        fout << left << setw(20) << word
                        << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end northwest search

            // Algorithm for searching for words in the northeast direction
            word = "";

            for (int k = 0; k < g.rows(); k++)
            {
                int loopAroundr = ((i - k + g.rows()) % g.rows());
                int loopAroundc = ((j + k + g.cols()) % g.cols());
                word += g.at(loopAroundr, loopAroundc);

                if (word.length() >= 5)
                {
                    index = dict.lookupWord(word);

                    if (index != -1)
                    {
                        // Stores i & j location as a string for formatting
                        // Writes found word in output.txt w/ location & index
                        string coords = "(" + to_string(i) + ", "
                            + to_string(j) + ")";
                        fout << left << setw(20) << word
                             << setw(20) << coords << index << endl;
                    } // end if
                } // end if
            } // end northeast search
        } // end column loop
    } // end row loop

    fout.close();
} // end findMatches

void search()
// Implements a global function search() which 
// - reads the name of the grid file from the keyboard, 
// - reads the data from input files for grid & dictionary,
// - sort all words in the dictionary, and 
// - prints out candidate words that can be found in the dictionary.
{
    // Reads the name of the grid file from the keyboard
    cout << "Enter the name of the grid file (with .txt): ";
    string gridFile;
    cin >> gridFile;
    Grid g(gridFile);

    // Reads the data from input files for grid & dictionary
    Dictionary dict;
    dict.readWords("Dictionary.txt");

    // Sorts all words in the dictionary
    dict.sortStandard("dict_sort_test.txt");

    // Finds all words from dictionary present in grid
    findMatches(dict, g);

    // Prints all candidate words that can be found in the dictionary. This
    // prints the contents of the output.txt file into terminal
    ifstream fin;
    string fileName = "output.txt";
    fin.open(fileName);

    if (!fin)
    {
        throw "File was not opened successfully";
    }

    cout << "Candidate words found in the dictionary:\n " << endl;
    string line;

    // prints each line of the output file
    while (getline(fin, line))
    {
        cout << line << endl;
    } // end while

    fin.close();
} // end search