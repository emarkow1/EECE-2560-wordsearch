//

#include "dictionary.h"

#include <cctype>
#include <chrono>


using namespace std;

// EMILES ADDITION BELOW
// Creates a version of the word containing only letters.
// The original word is not changed.
string Dictionary::makeSortKey(const string& word)
{
    string key;

    for (char character : word)
    {
        if (isalpha(static_cast<unsigned char>(character)))
        {
            key += character;
        }
    }

    return key;
}

// Determines whether left should appear before right.
bool Dictionary::comesBefore(const string& left, const string& right)
{
    // Compare
    return left < right;
}
// END OF EMILES ADDITION
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
        words.push_back(makeSortKey(word)); //not sure if makeSortKey is even needed tbh?
    }
    fin.close();
}

void Dictionary::sortWords(const string& filename) {
    auto start = std::chrono::system_clock::now();
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
    auto end = std::chrono::system_clock::now();
    cout << "Runtime: " << std::chrono::duration_cast<std::chrono::seconds>(end - start).count() << " s" << std::endl;
}

void Dictionary::sortStandard(const string& filename)
{
    ofstream fout;
    fout.open(filename.c_str());
    if (!fout)
    {
        throw "File not opened successfully";
    }
    sort(words.begin(), words.end());

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