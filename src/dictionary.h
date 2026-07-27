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
#include "heap.h"

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

        // Thiis function is used for testing purposes. It sorts the words using
        // the standard library sort to speed up the sorting process.
        void sortStandard(const string& filename);
        // sorts the words using the standard library sort. writes these sorted
        // words into the file "filename"

        int lookupWord(const string& target) const;
        // locates target in sorted word list using binary search. returns the
        // index of target (if found).

        void quicksortWords(const string& filename);

        void heapsortWords(const string& filename);
        // sorts the words using heapsort. writes these sorted words into the
        // file "filename"

        friend ostream& operator<<(ostream& os, const Dictionary& dict);
        // writes the words that are stored in dict to os.
    
    private:
        vector<string> words;
        // stores the dictionary words in their original order.
}; // end Dictionary class

#endif // DICTIONARY_H