// EECE 2560 Wordsearch Project
// 1-satbermacmar-2a
// dictionary.h
//
// This file declares the Dictionary class.
//

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Dictionary
// stores the Dictionary list of words in a vector. Includes operations that
// allow reading, printing, sorting, and searching the aforementioned words.
{
    public:
        Dictionary();
        // constructs an empty Dictionary object.

        void readWords(const string& filename);
        // reads the words from "filename" and stores them into the words
        // vector.

        void sortWords(const string& filename);
        // sorts the words using selection sort. writes these sorted words into
        // the file "filename"

        void sortStandard(const string& filename);
        // sorts the words using the standard library sort. writes these sorted
        // words into the file "filename"

        int lookupWord(const string& target) const;
        // locates target in sorted word list using binary search. returns the
        // index of target (if found).

        friend ostream& operator<<(ostream& os, const Dictionary& dict);
        // writes the words that are stored in dict to os.
    
    private:
        vector<string> words;
        // stores the dictionary words in their original order.
}; // end Dictionary class

#endif // DICTIONARY_H