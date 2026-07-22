//

#include "dictionary.h"
#include <cctype>


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
    string leftKey = makeSortKey(left);
    string rightKey = makeSortKey(right);

    // Compare while ignoring punctuation.
    if (leftKey != rightKey)
    {
        return leftKey < rightKey;
    }

    // If the letter-only versions are identical, put the
    // shorter original word first.
    //
    // Example: "cant" before "can't"
    if (left.length() != right.length())
    {
        return left.length() < right.length();
    }

    // Final tie-breaker.
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
        //altered BELOW - EMILE SATER
            if (comesBefore(words[j], words[min])) {
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

int Dictionary::lookupWord(const string& target) const {
    int first = 0;
    int last = words.size() - 1;
    while (first <= last) {
        int mid = floor((first + last) / 2);
        string midValue = words[mid];
        if (target == midValue) {
            return mid;
        }
        else if (target < midValue) {
            last = mid - 1;
        }
        else {
            first = mid + 1;
        }
    }
    return -1; 
}

ostream& operator<<(ostream& os, const Dictionary& dict) {
    for (int i = 0; i < dict.words.size(); i++) {
        os << dict.words[i] << " ";
    }
    return os;
}