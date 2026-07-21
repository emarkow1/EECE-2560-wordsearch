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

void Dictionary::sortWords(const string& filename) {
    ofstream fout;
    string fileName = filename;
    fout.open(fileName.c_str());
    if (!fout) {
        throw "File was not opened successfully";
    }

    for (int i = 0; i < (words.size() - 1); i++) {
        int min = i;
        for (int j = i + 1; j < words.size(); j++) {
            if (words[j] < words[min]) {
                min = j;
            }
        }
        swap(words[i], words[min]);
    }

    for (int i = 0; i < words.size(); i++) {
        fout << words[i] << endl;
    }
    fout.close();
}

void Dictionary::lookupWord(const string& word) const {
    
}

ostream& operator<<(ostream& os, const Dictionary& dict) {
    for (int i = 0; i < dict.words.size(); i++) {
        os << dict.words[i] << " ";
    }
    return os;
}