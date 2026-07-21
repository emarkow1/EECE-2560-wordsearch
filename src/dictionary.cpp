//

#include "dictionary.h"




Dictionary::Dictionary(){

}


void Dictionary::readWords(const string& filename) {  
    ifstream fin;
    string fileName = filename;
    fin.open(fileName.c_str());
    if (!fin) {
        throw "File was not opened successfully";
    }
    string word;
    while (fin >> word) {
        words.push_back(word);
    }
    fin.close();
}

void Dictionary::lookupWord(const string& word) const {
    
}

ostream& operator<<(ostream& os, const Dictionary& dict) {
    for (int i = 0; i < dict.words.size(); i++) {
        os << dict.words[i] << " ";
    }
    return os;
}