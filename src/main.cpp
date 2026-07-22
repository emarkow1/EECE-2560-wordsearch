
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
    cout << "word       start point (i, j)    found_index)" << endl;
    for (int i = 0; i < g.rows(); i++) {
        for (int j = 0; j < g.cols(); j++) {
            string word;
            for (int k = 0; k < g.rows(); k++) {
                int loopAround = (i + k) % g.rows();
                word += g.at(loopAround, j);
                if (word.length() >= 5) {
                    if (dict.lookupWord(word) != -1) {
                        cout << word <<  " (" << i << ", " << j << ") " <<  dict.lookupWord(word) << endl;
                    }
                }
            }
        }
    }

}


void search(){


}