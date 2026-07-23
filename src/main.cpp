
#include "grid.h"
#include "dictionary.h"
#include "d_except.h"
#include "d_matrix.h"
#include "iostream"

using namespace std;

void findMatches(const Dictionary& dict, const Grid& g);

int main() {

    Dictionary dict;
    //dict.readWords("Dictionary.txt");
    dict.readWords("dictionary-sorted.txt");
    dict.sortStandard("dict_sort_test.txt");
    //dict.sortWords("dict_sort_test.txt");
    //cout << dict << endl;
    cout << dict.lookupWord("Birthdate") << endl;
    Grid g("input15.txt");
    findMatches(dict, g);
    return 0;
}

void findMatches(const Dictionary& dict, const Grid& g) {
    ofstream fout;
    fout.open("output.txt");
    if (!fout) {
        throw "File was not opened successfully";
    }

    fout << "word       start point (i, j)    found_index" << endl;

    for (int i = 0; i < g.rows(); i++) {
        for (int j = 0; j < g.cols(); j++) {
            string word;
            for (int k = 0; k < g.rows(); k++) {
                int loopAround = (i + k) % g.rows();
                word += g.at(loopAround, j);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            for (int k = 0; k < g.rows(); k++) {
                int loopAround = (i - k + g.rows()) % g.rows();
                word += g.at(loopAround, j);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            for (int k = 0; k < g.cols(); k++) {
                int loopAround = (j + k) % g.cols();
                word += g.at(i, loopAround);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            for (int k = 0; k < g.cols(); k++) {
                int loopAround = (j - k + g.cols()) % g.cols();
                word += g.at(i, loopAround);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            // for diagonal
            for (int k = 0; k < g.rows(); k++) {
                int loopAroundr = ((i + k) % g.rows());
                int loopAroundc = ((j + k) % g.cols());
                word += g.at(loopAroundr, loopAroundc);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            for (int k = 0; k < g.rows(); k++) {
                int loopAroundr = ((i + k) % g.rows());
                int loopAroundc = ((j - k + g.cols()) % g.cols());
                word += g.at(loopAroundr, loopAroundc);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            for (int k = 0; k < g.rows(); k++) {
                int loopAroundr = ((i - k + g.rows()) % g.rows());
                int loopAroundc = ((j - k + g.cols()) % g.cols());
                word += g.at(loopAroundr, loopAroundc);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
            word = "";
            for (int k = 0; k < g.rows(); k++) {
                int loopAroundr = ((i - k + g.rows()) % g.rows());
                int loopAroundc = ((j + k + g.cols()) % g.cols());
                word += g.at(loopAroundr, loopAroundc);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        fout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
        }
    }
    fout.close();
}

/*Implement a global function search() which (1) reads the name of the grid file from the
keyboard, (2) read the data from input files for grid and dictionary, (3) sort all words in the
dictionary, and (4) prints out candidate words that can be found in the dictionary. */
void search(){
    cout << "Enter the name of the grid file: ";
    string gridFile;
    cin >> gridFile;
    Grid g(gridFile);
    Dictionary dict;
    dict.readWords("Dictionary.txt");
    dict.sortStandard("dict_sort_test.txt");
    findMatches(dict, g);

}