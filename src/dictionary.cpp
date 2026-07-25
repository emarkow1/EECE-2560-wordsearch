//

#include "dictionary.h"
#include <algorithm>
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

// readWords intakes the name of the dictionary txt file, opens it, 
// and reads the words then stores them in a words vector.
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

// sortWords intakes the name of the dictionary txt file, opens it, and sorts,
// the words using selectionsort and rewrites the sorted words to the txt file.
// This function also uses the chrono class to record the time the sorting
// takes and prints the runtime to console.
void Dictionary::sortWords(const string& filename) {
    auto start = chrono::system_clock::now();
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
    auto end = chrono::system_clock::now();
    cout << "Runtime: " << chrono::duration_cast<chrono::seconds>(end - start).count() << " s" << std::endl;
}
// sortStandard functions intakes the name of the dictionary txt file, opens it
// and iterates through each word, sorts it alphabetically, and rewrites 
// the sorted words to the txt file.
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
// lookupWord function takes the target word in the form of a string and
// uses binary search to search through the word list and then returns the
// index in which the target word is located within the dictionary object.
// If unsuccessful, returns -1.
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
// Overloaded output operator << to print the word list
ostream& operator<<(ostream& os, const Dictionary& dict) {
    for (int i = 0; i < dict.words.size(); i++) {
        os << dict.words[i] << " ";
    }
    return os;
}