
#include "grid.h"
#include "dictionary.h"
#include "d_except.h"
#include "d_matrix.h"
#include "iostream"


int main() {

    Dictionary dict;
    dict.readWords("Dictionary.txt");
    dict.sortWords("dict_sort_test.txt");
    //cout << dict << endl;

    return 0;
}

void findMatches(const Dictionary& dict, const Grid& g) {
    

}


void search(){


}